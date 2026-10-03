# Soldier Health Monitoring System

An ESP32-based prototype designed to demonstrate basic health monitoring and emergency communication concepts for field personnel. The system monitors heart rate and temperature, displays predefined status messages via a keypad, and sends sensor data and system status to a mobile dashboard via Blynk IoT.

## Features

- Heart-rate monitoring using a pulse sensor
- Temperature monitoring using a DHT11 sensor
- 16x2 I2C LCD for local health information
- 4x4 keypad for predefined status and alert messages
- Emergency button
- Emergency LED indication
- Wi-Fi connectivity
- Blynk IoT integration for remote monitoring
- Real-time transmission of:
  - Heart rate
  - Temperature
  - System status
  - Last selected status/alert message
  - Emergency button state

## Predefined Keypad Messages

| Key | Message |
|---|---|
| 1 | Need Backup |
| 2 | Injured |
| 3 | Enemy Seen |
| 4 | Mission Done |
| 5 | Need Medic |
| 6 | Low Ammo |
| 7 | Need Supply |
| 8 | Safe |
| 9 | Returning |
| 0 | Cancel Alert |
| * | SOS Alert |
| # | Status Sent |
| A | Alpha |
| B | Bravo |
| C | Charlie |
| D | Delta |

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

## Blynk IoT Integration

The ESP32 connects to a Wi-Fi network and communicates with the Blynk IoT platform.

The following virtual pins are used:

| Virtual Pin | Data |
|---|---|
| V0 | Heart rate (BPM) |
| V1 | Temperature |
| V2 | System status |
| V3 | Last status/alert message |
| V4 | Emergency button state |

The system updates the Blynk dashboard approximately once per second.

## How It Works

The ESP32 continuously reads the pulse sensor and DHT11 temperature sensor.

The pulse signal is processed to detect pulse peaks and estimate heart rate. A simple smoothing method is used to reduce rapid fluctuations in the calculated BPM.

Temperature readings from the DHT11 are also smoothed before being displayed.

The 16x2 I2C LCD displays the current heart rate and temperature.

The 4x4 keypad allows the user to select predefined status and alert messages. These messages are displayed locally and stored as the latest system message, which is then transmitted to Blynk.

The emergency button activates the emergency LED and changes the system status from `NORMAL` to `EMERGENCY`. The emergency state is also transmitted to Blynk.

## Software

The prototype was developed using the Arduino IDE and ESP32.

### Libraries Used

- Wire
- LiquidCrystal_I2C
- Keypad
- DHTesp
- WiFi
- WiFiClient
- BlynkSimpleEsp32

## Prototype Limitation

This project is an educational embedded-systems prototype. The sensors, algorithms, communication methods, and hardware used are not intended to replace certified medical, safety, or military equipment.

The heart-rate measurement is based on threshold-based pulse detection and is intended for demonstration purposes. More advanced signal processing, calibration, and validation would be required for reliable real-world measurements.

The DHT11 is also a basic temperature sensor and is used here for prototype demonstration rather than clinical measurement.

## Future Improvements

- GPS-based location tracking
- Improved heart-rate signal processing and filtering
- Battery-level monitoring
- Data logging and historical health-data visualization
- Improved wearable enclosure
- Secure wireless communication
- Dedicated emergency notification events
- Real-time location and health-data dashboard
- Integration of additional physiological sensors

## Project Status

**Prototype completed and tested.**

The project integrates embedded sensing, local user interaction, LCD-based monitoring, emergency indication, Wi-Fi connectivity, and IoT-based remote monitoring using an ESP32 and Blynk.


https://github.com/user-attachments/assets/c94bff0c-df0c-470d-b960-dcd1813de372









<img width="688" height="1042" alt="blynkIOT image" src="https://github.com/user-attachments/assets/a15fa554-13b6-4654-b0a3-b4688c289257" />



