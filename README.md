🌱 Greenhouse Controller

An Arduino-based automated greenhouse control system designed to monitor environmental conditions and control **ventilation, irrigation, and lighting**.

 📌 Project Overview

The system monitors temperature, light intensity, and soil moisture inside a greenhouse.

Based on the sensor readings, the controller automatically operates:

* A servo motor for greenhouse ventilation
* A water pump for irrigation
* A grow light for low-light conditions
* A warning LED for high-temperature conditions

 🎯 Objectives

* Monitor greenhouse environmental conditions
* Automatically control ventilation based on temperature
* Automate irrigation based on soil moisture
* Control grow lighting based on light intensity
* Provide a warning when temperature becomes too high

 🛠️ Technologies Used

* **Arduino**
* **Embedded C**
* **TMP36 Temperature Sensor**
* **LDR**
* **Soil Moisture Sensor / Potentiometer Simulation**
* **Servo Motor**
* **DC Motor / Water Pump**
* **L293D Motor Driver**
* **LEDs**

 🔧 Hardware Components

| Component            | Purpose                      |
| -------------------- | ---------------------------- |
| Arduino              | Main controller              |
| TMP36                | Measures temperature         |
| LDR                  | Detects light intensity      |
| Soil Moisture Sensor | Detects soil moisture        |
| Servo Motor          | Controls greenhouse window   |
| DC Motor / Pump      | Provides irrigation          |
| L293D                | Controls the DC motor        |
| Grow Light LED       | Provides additional lighting |
| Warning LED          | Indicates high temperature   |

 ⚙️ Working Principle

The controller continuously reads the environmental sensors and takes action according to predefined thresholds.

#🌡️ Temperature Control

When the temperature rises above the defined threshold:

* The servo motor opens the greenhouse window.
* The warning LED is turned ON.

 💧 Irrigation Control

When the soil becomes dry:

* The water pump is activated.
* Water is supplied to the plants.

 💡 Light Control

When the surrounding light level becomes low:

* The grow-light LED is turned ON.

 System Flow


       Sensors
          ↓
 ┌─────────────────┐
 │ Temperature     │
 │ Light           │
 │ Soil Moisture   │
 └────────┬────────┘
          ↓
      Arduino
          ↓
 ┌────────┼───────────┐
 ↓        ↓           ↓
Servo    Pump      Grow Light
 ↓        ↓           ↓
Window  Irrigation  Lighting


💻 Software

* Arduino IDE
* Embedded C
* Tinkercad / simulation environment

 🚀 Future Improvements

* Add IoT connectivity
* Monitor greenhouse conditions remotely
* Add humidity sensing
* Add automatic weather-based irrigation
* Add a mobile dashboard
* Store sensor data for analysis

 👩‍💻 Skills Demonstrated

Embedded Systems 
Arduino 
Sensor Interfacing 
Automation
Motor Control 
Servo Control 
ADC
Embedded C
IoT Concepts
