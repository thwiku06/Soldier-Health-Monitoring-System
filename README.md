# Soldier Health Monitoring System

An ESP32-based prototype designed to demonstrate basic health monitoring and emergency communication concepts for field personnel. The system monitors heart rate and temperature, provides predefined status alerts through a keypad, and uses Blynk IoT for mobile monitoring and alert communication.

## Features

- Heart-rate monitoring using a pulse sensor
- Temperature monitoring using a DHT11 sensor
- 16x2 I2C LCD for displaying health information
- 4x4 keypad for predefined status and alert messages
- Emergency button with LED indication
- Blynk IoT integration for mobile monitoring and alerts
- Predefined status and emergency alerts such as:
  - Need Backup
  - Injured
  - Enemy Seen
  - Mission Done
  - Need Medic
  - Low Ammo
  - Need Supply
  - SOS Alert
  - Safe
  - Returning
  - Cancel Alert

## Hardware

- ESP32 DevKit
- Pulse Sensor
- DHT11 temperature sensor
- 16x2 I2C LCD
- 4x4 membrane keypad
- Push button
- LED
- 220 Ω resistor
- Breadboard
- Jumper wires

## Pin Configuration

| Component | ESP32 Pin |
|---|---|
| Pulse Sensor | GPIO 34 |
| DHT11 | GPIO 4 |
| Emergency Button | GPIO 14 |
| Emergency LED | GPIO 27 |
| LCD SDA | GPIO 21 |
| LCD SCL | GPIO 22 |
| Keypad R1 | GPIO 13 |
| Keypad R2 | GPIO 5 |
| Keypad R3 | GPIO 26 |
| Keypad R4 | GPIO 25 |
| Keypad C1 | GPIO 23 |
| Keypad C2 | GPIO 33 |
| Keypad C3 | GPIO 18 |
| Keypad C4 | GPIO 19 |

**LCD I2C Address:** `0x27`

## Software

The prototype was developed using the Arduino IDE with an ESP32 board.

### Libraries Used

- Wire
- LiquidCrystal_I2C
- Keypad
- DHTesp
- Blynk library

## How It Works

The ESP32 continuously reads data from the pulse sensor and DHT11 temperature sensor.

The estimated heart rate and temperature are displayed on the 16x2 I2C LCD.

The 4x4 keypad allows the user to select predefined status and alert messages. An emergency button provides a dedicated emergency indication through the LED and connected monitoring system.

Blynk IoT is used to provide mobile monitoring and communicate selected alerts to a smartphone.

## Blynk IoT Integration

The system connects the ESP32 to the Blynk IoT platform, allowing sensor information and selected alerts to be monitored remotely through a mobile device.

This demonstrates how an embedded health-monitoring prototype can be extended from a standalone device into an IoT-enabled system.

## Prototype Limitation

This project is an educational embedded-systems prototype. The sensors, algorithms, communication methods, and hardware used are not intended to replace certified medical, safety, or military equipment.

The heart-rate measurement and temperature sensing are intended for demonstration purposes and may require improved sensing hardware, signal processing, calibration, and validation for reliable real-world applications.

## Future Improvements

- GPS-based location tracking
- More robust heart-rate signal filtering
- Battery-level monitoring
- Data logging and historical health-data visualisation
- Improved wearable enclosure and hardware integration through PCB design.
- Secure wireless communication
- More reliable emergency communication
- Integration of additional physiological sensors
- Real-time location and health-data dashboard

## Project Status

**Prototype completed and tested.**

The project demonstrates the integration of embedded sensing, user-input controls, local display, emergency indication, and IoT-based mobile monitoring using an ESP32.


https://github.com/user-attachments/assets/c94bff0c-df0c-470d-b960-dcd1813de372









<img width="688" height="1042" alt="blynkIOT image" src="https://github.com/user-attachments/assets/a15fa554-13b6-4654-b0a3-b4688c289257" />



