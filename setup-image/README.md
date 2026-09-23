# Project Setup Image

This folder contains the actual hardware setup photograph of the **Arduino Based Radar System for Object Detection**. The setup shows the Arduino Uno, HC-SR04 ultrasonic sensor mounted on the SG90 servo, 16×2 I2C LCD, green/red status LEDs, buzzer, potentiometer, breadboard and jumper-wire connections.

## Setup Photograph

![Radar System Hardware Setup](./1780160873743.jpg)

The photograph shows the physical prototype used for the project. The connection table below is taken from the current Arduino source code in `code/radar_system.ino`.

## Hardware Connections

| Component | Arduino Connection | Purpose |
|---|---|---|
| **HC-SR04 TRIG** | **D10** | Sends ultrasonic trigger pulse |
| **HC-SR04 ECHO** | **D11** | Receives echo pulse |
| **SG90 Servo Signal** | **D9** | Rotates the ultrasonic sensor |
| **Green LED** | **D2** | Indicates clear/out-of-range condition |
| **Red LED** | **D3** | Indicates object within warning range |
| **Buzzer** | **D8** | Audible warning when an object is detected within 20 cm |
| **16×2 I2C LCD SDA** | **A4 / SDA** | I2C data |
| **16×2 I2C LCD SCL** | **A5 / SCL** | I2C clock |
| **16×2 I2C LCD** | **I2C address 0x27** | Displays scan angle, distance and status |
| **Potentiometer** | **LCD contrast circuit** | Adjusts LCD contrast |

### Power Connections

- **Arduino 5V and GND** provide the supply rails for the sensor, LCD and other low-power modules.
- **HC-SR04** is powered from **5V and GND**.
- **SG90 servo** is connected to the **5V and GND** supply rails, with its signal wire connected to **D9**.
- **LEDs** are connected through current-limiting resistors.
- The **potentiometer** is used for LCD contrast adjustment; it is not read by the Arduino program as an analog input.

## Working Based on the Code

1. The **SG90 servo** sweeps the HC-SR04 from **0° to 180°** in **2° steps**.
2. At each angle, the HC-SR04 measures the distance to an object.
3. The measured **angle and distance** are sent through the Arduino serial port at **9600 baud**.
4. If the measured distance is **20 cm or less**, the **red LED and buzzer** are activated and the LCD shows a warning.
5. Otherwise, the **green LED** remains active and the LCD shows a clear status.
6. The Processing program reads the serial data and displays the radar visualization.

## Arduino Pin Summary

```text
Arduino UNO
│
├── D2  → Green LED
├── D3  → Red LED
├── D8  → Buzzer
├── D9  → SG90 Servo Signal
├── D10 → HC-SR04 TRIG
├── D11 → HC-SR04 ECHO
├── A4  → LCD SDA
└── A5  → LCD SCL
```

## Source Files

- Arduino firmware: [`../code/radar_system.ino`](../code/radar_system.ino)
- Processing visualization: [`../code/radar_visualization.pde`](../code/radar_visualization.pde)
- Setup photograph: [`./1780160873743.jpg`](./1780160873743.jpg)

> **Note:** The pin assignments documented here follow the current source code in the repository. This replaces the earlier pin mapping that did not match the actual firmware.