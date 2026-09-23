# Circuit Diagram & Hardware Connections

This folder contains the circuit diagram and verified hardware connection details for the **Arduino Based Radar System for Object Detection**.

## Circuit Diagram

![Radar Circuit Diagram](./circuitradar_circuit_diagram.png)

> **Connection note:** The pin mapping below follows the current Arduino firmware in `code/radar_system.ino` and the physical project setup.

## Verified Arduino UNO Pin Mapping

| Arduino UNO Pin | Component | Connection / Function |
|---|---|---|
| **D2** | Green LED | LED control through current-limiting resistor |
| **D3** | Red LED | LED control through current-limiting resistor |
| **D8** | Buzzer | Buzzer control |
| **D9** | SG90 Servo | Signal / control |
| **D10** | HC-SR04 | TRIG |
| **D11** | HC-SR04 | ECHO |
| **A4 / SDA** | 16×2 I2C LCD | I2C data |
| **A5 / SCL** | 16×2 I2C LCD | I2C clock |
| **5V** | HC-SR04, LCD, Servo supply | VCC / supply |
| **GND** | All modules and indicators | Common ground |

## 16×2 I2C LCD

- LCD type: **16×2 I2C**
- I2C address: **`0x27`**
- SDA: **A4 / SDA**
- SCL: **A5 / SCL**
- Powered from Arduino **5V and GND**.

## Potentiometer

The potentiometer visible in the physical setup is used for **LCD contrast adjustment**. It is part of the LCD hardware connection and is **not connected to A0 for measurement by the Arduino firmware**.

Therefore, **A0 is not a project sensor/input pin in the current code**.

## Power & Ground

- **HC-SR04:** VCC → 5V, GND → GND
- **SG90 servo:** VCC → 5V, GND → GND, signal → D9
- **16×2 I2C LCD:** VCC → 5V, GND → GND, SDA → A4, SCL → A5
- **Green and red LEDs:** controlled from D2 and D3 through current-limiting resistors
- **Buzzer:** controlled from D8
- All modules share a **common Arduino GND**.

## Object Detection & Alert Logic

The firmware uses a **20 cm warning threshold**:

| Condition | Green LED | Red LED | Buzzer | LCD |
|---|---:|---:|---:|---|
| Distance ≤ 20 cm | OFF | ON | ON | Object distance + `WARN!` |
| Distance > 20 cm | ON | OFF | OFF | `Status: CLEAR` |

## Radar Scanning

- Servo scan range: **0° to 180°**
- Scan step: **2°**
- HC-SR04 measures distance at each servo position
- Serial output: **9600 baud**
- Serial data format: `angle,distance.`
- Processing visualization reads the same serial data to display the radar interface.

## Hardware Flow

```text
                    ┌─────────────────────┐
                    │     Arduino UNO     │
                    └──────────┬──────────┘
                               │
       ┌───────────────────────┼────────────────────────┐
       │                       │                        │
       ▼                       ▼                        ▼
  HC-SR04 + SG90          16×2 I2C LCD          Alert Outputs
  D10 → TRIG              A4 → SDA             D2 → Green LED
  D11 → ECHO              A5 → SCL             D3 → Red LED
  D9  → Servo             0x27                 D8 → Buzzer
       │                       │
       └─────────────── 5V / GND ─────────────┘
```

## Source & Related Documentation

- Arduino firmware: [`../code/radar_system.ino`](../code/radar_system.ino)
- Processing visualization: [`../code/radar_visualization.pde`](../code/radar_visualization.pde)
- Physical setup: [`../setup-image/README.md`](../setup-image/README.md)

> **Important:** The current firmware does not configure or read `A0`. The earlier circuit documentation showing the potentiometer wiper connected to A0 has therefore been removed.
