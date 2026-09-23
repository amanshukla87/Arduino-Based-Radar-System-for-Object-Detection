# Documentation

Project documentation for the **Arduino Based Radar System for Object Detection**.

## Project Report

![Radar Project Report Cover](./radar-project-cover.png)

*Project report cover — Government Polytechnic Saharanpur, 2021–2022.*


## Project Scope

This project is a working Arduino-based prototype for ultrasonic object detection with angular scanning. The documentation covers the hardware setup, circuit connections, Arduino firmware, Processing visualization, and observed system behavior.

## System Summary

The Arduino UNO rotates an HC-SR04 ultrasonic sensor using an SG90 servo across a 0°–180° sweep. The measured angle and distance are used for local status indication and are transmitted over serial at 9600 baud to a Processing sketch for radar visualization.

The local interface consists of a 16×2 I2C LCD, green/red LEDs, and a piezo buzzer. The warning condition is based on a 20 cm distance threshold.

## Documentation Map

- [Circuit and Pin Mapping](../circuit/README.md) — verified Arduino-to-component connections.
- [Code Documentation](../code/README.md) — firmware, serial format, and Processing data flow.
- [Setup Image](../setup-image/README.md) — photograph and connection details of the assembled prototype.

## Project Status

The repository documents the completed prototype and its demonstrated hardware/software configuration. It does not claim features beyond the implemented Arduino firmware and Processing visualization.
