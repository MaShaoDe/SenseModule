# Sense-Module Core Firmware v1 – Skeleton

© Marcel Sauder · Sense Module · January 2026

This document defines the firmware skeleton for the Sense Module Hardware-Scope v1. It describes structure, responsibilities, and initialization order, without implementing application-specific logic.

The goal is a clean, readable, and extensible core firmware that supports bring-up, testing, and later feature growth.

## Naming Decision

The firmware core is named:

**Sense-Module Core**

Reasoning:

* Directly corresponds to the hardware term "Sense Module"
* Neutral and reusable
* Does not imply UI, application, or product-level behavior

## Scope of Sense-Module Core v1

Included:

* Hardware initialization
* Bus setup (I²C, SPI, 1-Wire)
* Peripheral detection
* Basic drivers and abstractions
* Status reporting (serial and display)

Explicitly not included:

* Application logic
* Business rules
* UI menus
* Network services beyond basic connectivity

## Firmware Architecture

```
firmware/
├── core/
│   ├── core_init.cpp
│   ├── core_status.cpp
│   ├── core_config.cpp
│   └── core_time.cpp
├── drivers/
│   ├── rtc_ds3231.cpp
│   ├── sensor_sht3x.cpp
│   ├── sensor_ds18b20.cpp
│   ├── display_ssd1306.cpp
│   └── storage_sd.cpp
├── hal/
│   ├── hal_i2c.cpp
│   ├── hal_spi.cpp
│   └── hal_gpio.cpp
├── config/
│   └── pin_assignment.h
├── main.cpp
└── README.md
```

## Initialization Order

1. Power and reset state
2. Serial console
3. GPIO configuration
4. I²C bus initialization
5. SPI bus initialization
6. RTC detection and time sync
7. Sensor detection
8. Display initialization
9. Storage initialization
10. Status summary output

## Core Responsibilities

### core_init

* System startup sequencing
* Centralized error handling
* Dependency ordering

### core_status

* Aggregated system state
* LED status signaling
* Serial status output
* Display status summary

### core_config

* Read jumper states
* Apply hardware configuration
* Provide runtime flags

### core_time

* RTC access
* System time abstraction
* Time validity state

## Error Handling Strategy

* No silent failures
* All hardware errors reported via serial
* Minimal visual indication via LEDs
* System continues operating where possible

## Coding Principles

* No dynamic memory allocation
* Explicit initialization
* Clear ownership of hardware resources
* One responsibility per module

## Target Environment

* ESP32 DevKitC V3
* Arduino framework or PlatformIO
* Hardware-Scope v1 pin assignment

This firmware skeleton is the foundation for all Sense Module firmware variants and extensions.
