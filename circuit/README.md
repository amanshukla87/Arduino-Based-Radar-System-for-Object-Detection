# Circuit

Hardware connection details for the **Arduino Based Radar System for Object Detection**.

## Pin Mapping

| Arduino UNO | Module / Component | Connection |
|---|---|---|
| D8 | Buzzer | Buzzer control |
| D9 | HC-SR04 | TRIG |
| D10 | HC-SR04 | ECHO |
| D11 | Servo motor | Signal |
| D12 | Green LED | Clear indication |
| D13 | Red LED | Object warning |
| A4 | I2C LCD | SDA |
| A5 | I2C LCD | SCL |
| 5V | Modules | Supply as appropriate |
| GND | All modules | Common ground |

## I2C LCD

The current firmware initializes the LCD at `0x27`, 16 columns × 2 rows.

## Object Warning

The firmware treats an object as a warning condition when `distance <= 20 cm`.

In that condition:
- Red LED: ON
- Green LED: OFF
- Buzzer: ON
- LCD: Shows distance and warning

For distances above the threshold, the green LED is enabled and the system reports a clear condition.

## Hardware Flow

```text
Arduino UNO
   │
   ├── HC-SR04 → Distance
   ├── Servo   → Angular scanning
   ├── LCD     → Status display
   ├── LEDs    → Visual indication
   └── Buzzer  → Audible warning
```

Refer to the project root README for the complete system overview.
