

#include <Servo.h>


// Pin definitions


// TMP36 temperature sensor
#define TEMP_PIN A0

// LDR
#define LDR_PIN A1

// Potentiometer used to simulate soil moisture
#define SOIL_MOISTURE_PIN A2

// Grow light LED
#define GROW_LIGHT_LED 7

// Warning LED
#define WARNING_LED 8

// Servo motor for greenhouse window
#define SERVO_PIN 9

// L293D motor driver
#define MOTOR_IN1 10
#define MOTOR_IN2 11
#define MOTOR_ENABLE 6

Servo windowServo;


// Thresholds


#define TEMPERATURE_THRESHOLD 30.0
#define LIGHT_THRESHOLD 500
#define SOIL_MOISTURE_THRESHOLD 40

void setup()
{
  Serial.begin(9600);

  pinMode(GROW_LIGHT_LED, OUTPUT);
  pinMode(WARNING_LED, OUTPUT);

  pinMode(MOTOR_IN1, OUTPUT);
  pinMode(MOTOR_IN2, OUTPUT);
  pinMode(MOTOR_ENABLE, OUTPUT);

  windowServo.attach(SERVO_PIN);

  // Initial conditions
  windowServo.write(0);

  digitalWrite(GROW_LIGHT_LED, LOW);
  digitalWrite(WARNING_LED, LOW);

  digitalWrite(MOTOR_IN1, LOW);
  digitalWrite(MOTOR_IN2, LOW);
  analogWrite(MOTOR_ENABLE, 0);

  Serial.println("Greenhouse Controller");
  Serial.println("---------------------");
}

void loop()
{

  // Read sensors


  int tempRaw = analogRead(TEMP_PIN);
  int ldrValue = analogRead(LDR_PIN);
  int soilRaw = analogRead(SOIL_MOISTURE_PIN);

 
  // Convert TMP36 reading
  

  float voltage = tempRaw * (5.0 / 1023.0);

  float temperature = (voltage - 0.5) * 100.0;

  
  // Convert soil reading
 

  int soilMoisture = map(soilRaw, 0, 1023, 0, 100);
  soilMoisture = constrain(soilMoisture, 0, 100);

  
  // Display sensor readings
  

  Serial.println("---------------------");

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  Serial.print("LDR Value: ");
  Serial.println(ldrValue);

  Serial.print("Soil Moisture: ");
  Serial.print(soilMoisture);
  Serial.println(" %");


  // Temperature control
  

  if (temperature > TEMPERATURE_THRESHOLD)
  {
    windowServo.write(90);

    digitalWrite(WARNING_LED, HIGH);

    Serial.println("High temperature!");
    Serial.println("Window: OPEN");
    Serial.println("Warning LED: ON");
  }
  else
  {
    windowServo.write(0);

    digitalWrite(WARNING_LED, LOW);

    Serial.println("Temperature normal.");
    Serial.println("Window: CLOSED");
    Serial.println("Warning LED: OFF");
  }

  
  // Light control
 

  if (ldrValue < LIGHT_THRESHOLD)
  {
    digitalWrite(GROW_LIGHT_LED, HIGH);

    Serial.println("Low light detected.");
    Serial.println("Grow Light: ON");
  }
  else
  {
    digitalWrite(GROW_LIGHT_LED, LOW);

    Serial.println("Sufficient light detected.");
    Serial.println("Grow Light: OFF");
  }


  // Irrigation control
 

  if (soilMoisture < SOIL_MOISTURE_THRESHOLD)
  {
    // Turn water pump ON
    digitalWrite(MOTOR_IN1, HIGH);
    digitalWrite(MOTOR_IN2, LOW);
    analogWrite(MOTOR_ENABLE, 200);

    Serial.println("Soil is dry.");
    Serial.println("Water Pump: ON");
  }
  else
  {
    // Turn water pump OFF
    digitalWrite(MOTOR_IN1, LOW);
    digitalWrite(MOTOR_IN2, LOW);
    analogWrite(MOTOR_ENABLE, 0);

    Serial.println("Soil moisture sufficient.");
    Serial.println("Water Pump: OFF");
  }

  delay(1000);
}
