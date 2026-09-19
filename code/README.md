# Code

Source code for the **Arduino Based Radar System for Object Detection**.

## Files

### `radar_system.ino`

Arduino firmware that:
- Controls the servo scanning mechanism.
- Reads the HC-SR04 ultrasonic sensor.
- Displays angle and status on the I2C LCD.
- Activates LEDs and buzzer according to the 20 cm warning threshold.
- Sends angle and distance over serial at **9600 baud**.

Serial format:

```text
angle,distance.
```

### `radar_visualization.pde`

Processing sketch that receives the Arduino serial stream and renders radar range arcs, angular sweep, detected object position, distance/angle information, and status.

The current Processing sketch uses **COM3** and **9600 baud**. If the Arduino uses another serial port, update the port value before running it.

## Data Flow

```text
HC-SR04
   ↓
Arduino UNO
   ↓
angle,distance. over Serial
   ↓
Processing
   ↓
Radar Visualization
```
