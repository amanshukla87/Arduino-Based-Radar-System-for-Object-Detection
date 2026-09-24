# Arduino Based Radar System for Object Detection

An Arduino-based radar prototype built during my **Diploma in Electronics Engineering** to understand ultrasonic sensing, servo control, embedded programming, and serial visualization.

The idea is simple: rotate an **HC-SR04 ultrasonic sensor** with an **SG90 servo**, measure the distance at different angles, and send the readings to a computer where **Processing** displays them as a radar-style interface.

## Project Highlights

- **Arduino UNO** as the main controller
- **HC-SR04** for ultrasonic distance measurement
- **SG90** for 0°–180° scanning
- **16×2 I2C LCD** for local status
- **Green LED, red LED and buzzer** for object indication
- **Processing** for computer-based radar visualization
- Serial communication at **9600 baud**
- Warning threshold set to **20 cm**

## Project Achievement

🏅 **Silver Medal — Institutional Project Exhibition**

This was my **Diploma final-year project** and one of my early hands-on projects in embedded systems. It gave me practical experience with Arduino programming, sensors, motors, display interfacing, and debugging a complete hardware setup.

## How It Works

The SG90 servo moves the HC-SR04 between **0° and 180° in 2° steps**.

At every position:

1. The servo moves to the required angle.
2. The HC-SR04 sends an ultrasonic pulse and measures the return time.
3. The Arduino converts that measurement into distance.
4. The angle and distance are shown on the LCD and sent over serial.
5. If an object is **20 cm or closer**, the red LED and buzzer turn on.
6. Otherwise, the green LED indicates a clear condition.
7. Processing reads the serial data and draws the radar sweep.

The Arduino sends data in this format:

```text
angle,distance.
```

Example:

```text
90,18.
```

## Hardware

| Component | Purpose |
|---|---|
| **Arduino UNO** | Main controller |
| **HC-SR04** | Distance measurement |
| **SG90 Servo** | Rotates the ultrasonic sensor |
| **16×2 I2C LCD** | Displays angle and status |
| **Green LED** | Clear condition |
| **Red LED** | Object warning |
| **Buzzer** | Audible warning |
| **Potentiometer** | LCD contrast adjustment |
| **Jumper Wires** | Hardware connections |

## Arduino Pin Mapping

The table below follows the current firmware in `code/radar_system.ino`.

| Arduino UNO | Connected Component | Function |
|---|---|---|
| **D2** | Green LED | Clear indication |
| **D3** | Red LED | Warning indication |
| **D8** | Buzzer | Warning output |
| **D9** | SG90 Servo | Servo control signal |
| **D10** | HC-SR04 | TRIG |
| **D11** | HC-SR04 | ECHO |
| **A4 / SDA** | 16×2 I2C LCD | I2C data |
| **A5 / SCL** | 16×2 I2C LCD | I2C clock |

The LCD uses I2C address **`0x27`**.

The potentiometer is part of the LCD contrast circuit and is **not read by the Arduino firmware as an analog input**.

## Hardware Setup

![Radar Project Setup](./setup-image/1780160873743.jpg)

This is the physical prototype used during the project. The setup includes the Arduino UNO, servo-mounted HC-SR04, LCD, LEDs, buzzer, potentiometer, breadboard, and jumper-wire connections.

## Circuit Diagram

![Radar Circuit Diagram](./circuit/circuitradar_circuit_diagram.png)

The circuit connects the Arduino with the ultrasonic sensor, servo, LCD, LEDs, and buzzer.

More connection details are available in the [circuit documentation](./circuit/README.md).

## Radar Visualization

The Processing sketch receives the Arduino data and displays:

- Radar sweep
- Current angle
- Measured distance
- Object status
- Object position when it is within the warning range

The current Processing sketch is configured for **COM3 at 9600 baud**. Change the serial-port value in `code/radar_visualization.pde` if the Arduino appears on a different port.

## Software

### Arduino

- C/C++
- Arduino IDE
- Servo library
- Wire library
- LiquidCrystal_I2C library

### Processing

- Processing
- Processing Java Mode
- Serial communication

## System Flow

```text
HC-SR04
   │
   ▼
Arduino UNO ──► LCD
   │
   ├──► Green LED / Red LED / Buzzer
   │
   └──► Serial: angle,distance.
                    │
                    ▼
                Processing
                    │
                    ▼
             Radar Visualization
```

## Source Code

### Arduino Firmware

[`code/radar_system.ino`](./code/radar_system.ino)

Handles:

- Servo scanning
- HC-SR04 distance measurement
- LCD output
- LED and buzzer control
- Serial data transmission

### Processing Visualization

[`code/radar_visualization.pde`](./code/radar_visualization.pde)

Handles:

- Serial data reception
- Radar graphics
- Angle and distance display
- Object warning visualization

## Project Structure

```text
Arduino-Based-Radar-System-for-Object-Detection/
├── code/
│   ├── README.md
│   ├── radar_system.ino
│   └── radar_visualization.pde
├── circuit/
│   ├── README.md
│   └── circuitradar_circuit_diagram.png
├── document/
│   ├── README.md
│   └── radar-project-cover.png
├── setup-image/
│   ├── README.md
│   └── 1780160873743.jpg
├── video/
│   └── README.md
└── README.md
```

## What I Learned

This project was one of my first complete hardware-software systems. More than just making the radar display work, it helped me understand how individual parts of an embedded system come together:

- Reading sensors from a microcontroller
- Controlling a servo motor
- Working with I2C displays
- Using digital outputs for alerts
- Sending structured data over serial
- Connecting embedded hardware with a PC visualization
- Debugging hardware and software together

## Project Status

**Completed — Diploma Final-Year Project**

The repository contains the implemented Arduino firmware, Processing visualization, circuit documentation, and hardware setup used for the project.

## Documentation

- [Circuit & Pin Mapping](./circuit/README.md)
- [Code Documentation](./code/README.md)
- [Hardware Setup](./setup-image/README.md)
- [Project Documentation](./document/README.md)

## Author

**Aman Shukla**

Diploma in Electronics Engineering  
Government Polytechnic Saharanpur

