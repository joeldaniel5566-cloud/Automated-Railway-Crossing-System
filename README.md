# 🚦 Automated Railway Crossing System

An Arduino-based automated railway crossing system designed to improve railway crossing safety by automatically detecting approaching trains and controlling railway gates.

The system uses ultrasonic sensors to detect train movement, servo motors to operate the gates, and LED indicators, a buzzer, and an LCD display to provide warning signals.

## 📌 Project Overview

The Automated Railway Crossing System is designed to minimise human intervention at railway crossings.

It uses two ultrasonic sensors:
- **Sensor 1 (Entry Detection):** Detects an approaching train and triggers the gate-closing mechanism.
- **Sensor 2 (Exit Detection):** Detects when the train has passed the crossing and triggers the gate-opening mechanism.

The Arduino processes sensor inputs and controls all the connected components accordingly.

## ✨ Features

- Automatic train detection using ultrasonic sensors.
- Automatic railway gate opening and closing using servo motors.
- Red and green LED indicators for traffic signals.
- Buzzer alerts when a train approaches.
- LCD display for real-time status updates.
- Dual-sensor detection mechanism.

## 🛠️ Components Used

| Component | Quantity |
|---|---:|
| Arduino Board | 1 |
| HC-SR04 Ultrasonic Sensors | 2 |
| Servo Motors | 2 |
| I2C LCD Display (16x2) | 1 |
| Red LEDs | 2 |
| Green LEDs | 2 |
| Buzzer | 1 |
| 220Ω Resistors | As required |
| Breadboard | 1 |
| Jumper Wires | As required |

## ⚙️ Working Principle

### 1. Initial State
- Both railway gates remain open.
- Green LEDs remain ON.
- LCD displays the welcome message.

### 2. Train Detection
- The first ultrasonic sensor detects an approaching train.
- When an object is detected within the configured distance, the Arduino initiates the warning sequence.

### 3. Gate Closing
- Both red LEDs turn ON.
- Green LEDs turn OFF.
- The buzzer generates an alert.
- Servo motors rotate to close the railway gates.
- LCD displays the train warning and gate status.

### 4. Train Passing
- The gates remain closed while the train passes through the crossing.

### 5. Train Exit Detection
- The second ultrasonic sensor detects the train after it passes the crossing.

### 6. Gate Opening
- Red LEDs turn OFF.
- Green LEDs turn ON.
- Servo motors return to their initial positions.
- LCD displays "Safe to Go" and "Gate Open".

## 💻 Technologies Used

- Arduino Programming (C/C++)
- Arduino IDE
- Embedded Systems
- Ultrasonic Distance Sensors
- Servo Motor Control
- I2C LCD Communication

## 📂 Project Structure

```text
Automated-Railway-Crossing-System/
│
├── Arduino/
│   └── Railway_Crossing_System.ino
│
├── Documentation/
│   └── Railway_Crossing_System.docx
│
├── Images/
│   ├── circuit-diagram.png
│   └── hardware-setup.jpg
│
└── README.md
```

## 🚀 How to Run

1. Download or clone this repository.
2. Open the `.ino` file using Arduino IDE.
3. Install the following Arduino libraries:
   - Servo
   - LiquidCrystal_I2C
4. Connect the components according to the circuit configuration.
5. Select the appropriate Arduino board and COM port.
6. Upload the code to the Arduino board.
7. Power the circuit and observe the automated gate operation.

## 🎯 Applications

- Automated railway crossings.
- Railway safety demonstration models.
- Smart transportation systems.
- Educational embedded systems projects.

## 👥 Project Team

This was developed as a group project.

**Team Members:**
- [Member 1]
- [Member 2]
- [Member 3]
- [Member 4]

## ⚠️ Disclaimer

This project is an educational prototype demonstrating automated railway crossing functionality. It is not certified or designed for deployment in real railway infrastructure.
