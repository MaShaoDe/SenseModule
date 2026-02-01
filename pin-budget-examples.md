# Pin Budget Examples for ESP32

This document provides **practical pin-budget examples** for common ESP32 use cases.

The goal is to make GPIO consumption visible early in the design phase, before schematic capture or PCB layout. Numbers are intentionally conservative and assume clean separation of concerns.

All examples focus on **usable GPIOs**, not theoretical maximums.

© Marcel Sauder, 2026

## General Assumptions

Unless stated otherwise, the following assumptions apply:
– SPI uses shared MOSI, MISO, SCK
– Each SPI device needs its own CS line
– I²C uses shared SDA and SCL
– UART refers to one additional hardware UART besides USB/console
– Bootstrapping and strapping pins are avoided where possible

## Example 1: Sensor Node (I²C + UART)

Typical use case:
– Environmental sensor node
– Data logger
– Simple gateway

Interfaces:
– I²C sensors (temperature, humidity, pressure)
– One UART device (GPS, RS485, debug)
– Status LED

Pin budget:
– I²C SDA: 1
– I²C SCL: 1
– UART TX: 1
– UART RX: 1
– Status LED: 1

Total GPIOs used: 5

Recommended ESP32:
– ESP32-C3
– ESP32-WROOM-32

## Example 2: Relay Controller (8-channel)

Typical use case:
– Home automation
– Campervan or automotive control
– Industrial switching

Interfaces:
– 8 relay outputs
– 2 status LEDs
– Optional enable or safety input

Pin budget:
– Relay outputs: 8
– Status LEDs: 2
– Enable / safety input: 1

Total GPIOs used: 11

Recommended ESP32:
– ESP32-C3
– ESP32-WROOM-32

Note:
For larger relay counts, consider shift registers or I/O expanders.

## Example 3: TFT Display with Touch (SPI)

Typical use case:
– User interface
– Control panel
– Instrument display

Interfaces:
– SPI TFT display
– SPI touch controller
– Backlight control

Pin budget:
– SPI MOSI: 1
– SPI MISO: 1
– SPI SCK: 1
– TFT CS: 1
– TFT DC: 1
– TFT RESET: 1
– Touch CS: 1
– Backlight PWM: 1

Total GPIOs used: 8

Recommended ESP32:
– ESP32-S3
– ESP32-WROVER
– ESP32-WROOM-32 (38-pin)

## Example 4: TFT + Touch + SD Card (Shared SPI)

Typical use case:
– GUI device with data logging
– Measurement instrument

Interfaces:
– SPI TFT display
– SPI touch controller
– SPI SD card

Pin budget:
– SPI MOSI: 1
– SPI MISO: 1
– SPI SCK: 1
– TFT CS: 1
– TFT DC: 1
– TFT RESET: 1
– Touch CS: 1
– SD CS: 1
– Backlight PWM: 1

Total GPIOs used: 9

Recommended ESP32:
– ESP32-S3
– ESP32-WROVER

## Example 5: GUI Device with I²C + SPI + UART

Typical use case:
– Advanced control panel
– Configuration interface

Interfaces:
– SPI TFT display
– I²C sensors or RTC
– One UART device
– Buzzer or feedback output

Pin budget:
– SPI MOSI: 1
– SPI MISO: 1
– SPI SCK: 1
– TFT CS: 1
– TFT DC: 1
– TFT RESET: 1
– I²C SDA: 1
– I²C SCL: 1
– UART TX: 1
– UART RX: 1
– Buzzer / feedback: 1

Total GPIOs used: 11

Recommended ESP32:
– ESP32-S3
– ESP32-WROOM-32 (38-pin)

## Example 6: Minimal IoT Node

Typical use case:
– Battery-powered node
– Simple sensor + Wi-Fi

Interfaces:
– One digital sensor
– One status LED

Pin budget:
– Sensor input: 1
– Status LED: 1

Total GPIOs used: 2

Recommended ESP32:
– ESP32-C2
– ESP32-C3

## Design Notes

– Always reserve 2–4 GPIOs as safety margin
– Avoid strapping pins unless absolutely necessary
– Check boot mode requirements early
– Consider I/O expanders (I²C, SPI) for scalability

This file is intended to live in:

```
docs/pin-budget-examples.md
```

and complements the main README.md in the repository root.
