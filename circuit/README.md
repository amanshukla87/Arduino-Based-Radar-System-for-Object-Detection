# Circuit

Hardware connection details for the **Arduino Based Radar System for Object Detection**.

## Pin Mapping

| Arduino UNO | Module / Component | Connection |
|---|---|---|
| D2 | Green LED | Anode / control |
| D3 | Red LED | Anode / control |
| D8 | Piezo buzzer | Positive / control |
| D9 | SG90 servo | Signal |
| D10 | HC-SR04 | TRIG |
| D11 | HC-SR04 | ECHO |
| A0 | Potentiometer | Wiper |
| A4 / SDA | 16x2 I2C LCD | SDA |
| A5 / SCL | 16x2 I2C LCD | SCL |
| 5V | HC-SR04, servo, LCD | Supply |
| GND | Modules and indicators | Common ground |

The LEDs are connected to ground through resistors. The potentiometer is connected across 5V and GND, with its wiper connected to A0.

The Arduino UNO R3 provides A4/SDA and A5/SCL for I2C communication.

## I2C LCD

The current firmware initializes the LCD as a 16-column × 2-row display at I2C address `0x27`.

## Object Warning

The firmware uses a **20 cm** distance threshold.

When an object is detected within the warning range:
- Red LED: ON
- Green LED: OFF
- Buzzer: ON
- LCD: Shows distance and warning status

For distances above the threshold, the green LED is enabled and the system reports a clear condition.

## Hardware Flow

```text
Arduino UNO
   │
   ├── HC-SR04 → Distance measurement
   ├── SG90 servo → Angular scanning
   ├── 16x2 I2C LCD → Status display
   ├── LEDs → Visual indication
   ├── Piezo buzzer → Audible warning
   └── Potentiometer → Analog input
```

The assembled hardware is shown in [Setup Image](../setup-image/README.md).
