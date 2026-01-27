# Hardware-Scope v1 – Test Environment

© Marcel Sauder · Sense Module · January 2026

This document describes the complete hardware test environment for the Sense Module base project (Hardware-Scope v1). It serves as a reference for setup, testing, and firmware development. The list is intentionally complete and closed.

## MCU and Wireless

* ESP32 DevKitC V3
* ESP32-WROOM-32U (external antenna)
* 2.4 GHz adhesive antenna

  * U.FL / IPX connector

## Power Supply (Development)

* Breadboard power supply module
* Input via USB-C or laboratory power supply
* Outputs:

  * 5 V regulated
  * 3.3 V regulated

## Time Base

* RTC module DS3231M
* I²C interface
* Coin cell holder for backup battery

## Sensors

* SHT31 or GY-SHT30-D

  * Temperature and relative humidity
  * I²C

* DS18B20 temperature sensor with cable

  * Temperature
  * 1-Wire

## Storage

* microSD card module
* SPI interface
* Integrated voltage regulator and level shifting

## Display

* OLED display 0.91 inch
* Controller SSD1306
* Resolution 128 × 32
* I²C
* Monochrome

## Status and User Interface Elements

* THT LEDs

  * Red
  * Green
  * 3 mm or 5 mm

* Series resistors

  * 1 kΩ
  * ¼ W
  * One resistor per LED

* PCB-mounted micro push buttons

  * Reset button (EN to GND)
  * User button (GPIO to GND, internal pull-up)

## Configuration

* Classic 2-pin jumpers

  * Simple hardware configuration
  * For example I²C pull-ups or optional SD functionality

This hardware setup forms the basis for all further tests, firmware experiments, and system verification within Hardware-Scope v1.
