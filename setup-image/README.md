# Setup Image

Photograph of the assembled Arduino-based radar system, showing the Arduino Uno, HC-SR04 ultrasonic sensor mounted on the SG90 servo, 16x2 I2C LCD, LEDs, buzzer, and potentiometer.

## Hardware Connections

| Component | Connection |
|---|---|
| Green LED | D2 |
| Red LED | D3 |
| Piezo buzzer | D8 |
| SG90 servo signal | D9 |
| HC-SR04 Trig | D10 |
| HC-SR04 Echo | D11 |
| Potentiometer wiper | A0 |
| 16x2 I2C LCD SDA | SDA / A4 |
| 16x2 I2C LCD SCL | SCL / A5 |

The LEDs are connected to ground through resistors. The HC-SR04 and servo use the breadboard 5V and GND rails. The LCD I2C module is powered from the Arduino 5V and GND connections.

## Setup Photo

[1780160873743.jpg](./1780160873743.jpg)
