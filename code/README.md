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

### Hardware Interface

| Component | Arduino Uno Pin |
|---|---|
| Green LED | D2 |
| Red LED | D3 |
| Piezo buzzer | D8 |
| SG90 servo signal | D9 |
| HC-SR04 Trig | D10 |
| HC-SR04 Echo | D11 |
| Potentiometer wiper | A0 |
| LCD SDA | SDA / A4 |
| LCD SCL | SCL / A5 |

The LCD uses the I2C interface. The HC-SR04 and servo are powered from the breadboard 5V and GND rails.

### Serial Format

The Arduino sends each measurement in the following format:

```text
angle,distance.
```

For example:

```text
90,18.
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
