# ESP32 Pin Assignment v1 – Test Environment

© Marcel Sauder · Sense Module · January 2026

This document defines the ESP32 pin assignment for the Hardware-Scope v1 test environment. The goal is a clear, conflict-free, and reproducible wiring scheme suitable for breadboard-based testing and firmware development.

The assignments are conservative and leave room for later expansion.

## MCU Reference

* Board: ESP32 DevKitC V3
* Module: ESP32-WROOM-32U
* Logic level: 3.3 V

## Power

* 5 V: provided by breadboard power supply module
* 3.3 V: provided by breadboard power supply module
* GND: common ground for all modules

## I²C Bus

Used for RTC, environmental sensor, and OLED display.

* SDA: GPIO 21
* SCL: GPIO 22

Notes:

* Internal ESP32 pull-ups disabled
* External pull-ups enabled via jumper if required
* All I²C devices share the same bus

## SPI Bus (microSD)

Dedicated SPI bus for storage.

* MOSI: GPIO 23
* MISO: GPIO 19
* SCK: GPIO 18
* CS (SD): GPIO 5

Notes:

* CS is exclusive to the SD module
* SPI bus not shared with display

## 1-Wire Bus (DS18B20)

* Data: GPIO 4

Notes:

* Internal pull-up enabled in software
* External pull-up may be added if cable length requires it

## Status LEDs

* Green LED: GPIO 16
* Red LED: GPIO 17

Notes:

* Each LED uses a 1 kΩ series resistor
* LEDs connected to GPIO → resistor → LED → GND

## Buttons

* Reset button:

  * ESP32 EN pin to GND

* User button:

  * GPIO 27 to GND
  * Internal pull-up enabled in software

## Configuration Jumpers

* Jumper 1: I²C pull-up enable
* Jumper 2: SD module enable (CS or power gating)

## Reserved / Free GPIOs

The following GPIOs are intentionally left unassigned for future use:

* GPIO 12
* GPIO 13
* GPIO 14
* GPIO 25
* GPIO 26
* GPIO 32
* GPIO 33

## Notes

* Bootstrapping pins (GPIO 0, 2, 15) are avoided for external connections
* All assignments are valid for breadboard-based testing
* Pin usage may be revised in later hardware revisions

This pin assignment is the authoritative reference for Hardware-Scope v1 firmware development and testing.
