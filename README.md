# Arduino Based Radar System for Object Detection

An Arduino-based radar prototype that scans a defined angular range using an **HC-SR04 ultrasonic sensor mounted on a servo motor**. Measured angle and distance are sent over serial communication to a **Processing** visualization, while an LCD, LEDs, and buzzer provide local status indication.

## Project Overview

The system scans from **15° to 165°** and back. At each position, the ultrasonic sensor measures distance.

- Warning threshold: **20 cm**
- Serial communication: **9600 baud**
- Data format: `angle,distance.`
- Processing visualizes the scan.
- Red LED and buzzer indicate an object within the warning distance.
- Green LED indicates a clear condition.
- 16×2 I2C LCD displays angle and status.

## Hardware

| Component | Purpose |
|---|---|
| Arduino UNO | Main controller |
| HC-SR04 | Ultrasonic distance measurement |
| Servo motor | Sensor rotation |
| 16×2 I2C LCD | Local display |
| Green LED | Clear indication |
| Red LED | Object warning |
| Buzzer | Audible warning |

## Pin Mapping

| Arduino Pin | Component | Function |
|---|---|---|
| D8 | Buzzer | Warning output |
| D9 | HC-SR04 TRIG | Trigger |
| D10 | HC-SR04 ECHO | Echo |
| D11 | Servo | Signal |
| D12 | Green LED | Clear indication |
| D13 | Red LED | Warning indication |
| A4 | I2C LCD | SDA |
| A5 | I2C LCD | SCL |

The LCD uses address **0x27** in the current firmware.

## How It Works

```text
Servo rotates
     ↓
HC-SR04 measures distance
     ↓
Arduino checks threshold
     ↓
LCD + LEDs + buzzer show status
     ↓
Angle + distance sent over Serial
     ↓
Processing visualizes radar scan
```

## Code

- `code/radar_system.ino` — Arduino scanning, distance measurement, alerts, LCD output, and serial transmission.
- `code/radar_visualization.pde` — Processing radar visualization.

## Running

1. Connect the hardware according to the pin mapping.
2. Upload `code/radar_system.ino` to the Arduino UNO.
3. Verify serial output at **9600 baud**.
4. Open the Processing sketch.
5. Set the serial port to the Arduino's actual port.
6. Run the Processing sketch.

## Project Structure

```text
Arduino-Based-Radar-System-for-Object-Detection/
├── code/
├── document/
├── circuit/
├── setup-image/
├── video/
└── README.md
```

## Project Status

**Status: Completed Prototype**

## Author

**Aman Shukla**  
B.Tech Electronics Engineering | Sensors & Transducers Technology
