# 08 Reference Design – Sense Satellite (ESP32-W1)

Version: 0.1 (Reference – Architectural)
Date: 2026-01-29
Author: Marcel Sauder
Project: SenseModule / SenseCore

## 1. Scope and Intent

This document defines the **hardware reference design** for a Sense Satellite node based on the **ESP32-W1**.

It describes the **mandatory building blocks, electrical architecture, and interfaces** required to implement a Sense Satellite compliant with the SenseCore contract and the Hardware Profile – Sense Satellite.

This is **not** a PCB design, schematic, or BOM. It is an architectural reference intended to guide consistent hardware implementations.

## 2. Role Definition

The Sense Satellite is a strictly measuring and delivering node. It operates unattended, without user interaction, display, or local analytics.

The ESP32-W1 is used as a single, unified MCU platform to ensure robustness, memory headroom, and long-term maintainability.

## 3. Core Components

### 3.1 Microcontroller

* ESP32-W1 (reference and minimum platform)
* Integrated Wi-Fi (optional LoRa via external module)
* Deep sleep capable
* Hardware watchdog enabled

### 3.2 Non-Volatile Storage

Local non-volatile storage is mandatory.

Supported options:

* SPI NOR Flash
* FRAM (preferred for high write cycles)

SD cards are explicitly excluded.

Storage holds:

* time-stamped sensor measurements
* delivery state metadata

### 3.3 Time Base

A reliable time reference is required.

Options:

* external RTC with backup cell
* network-based time synchronization on wake

Time accuracy requirements are relaxed and optimized for long sleep cycles.

### 3.4 Power Supply

The Sense Satellite may operate from:

* battery
* solar
* hybrid systems

Power subsystem requirements:

* wide input tolerance
* low quiescent current
* brownout detection enabled

The power design must support deep sleep as the dominant state.

## 4. Sensor Interface Architecture

Sensors are connected using simple, low-overhead buses.

Supported buses:

* I²C (preferred)
* OneWire (optional)
* analog input (optional, buffered)

All sensors are powered and read **serially**, never in parallel.

Sensor power switching is recommended to minimize idle consumption.

## 5. Communication Interface

Primary communication:

* Wi-Fi (ESP32-W1 integrated)

Optional communication:

* LoRa via SPI-connected module

Communication characteristics:

* event-based activation
* no continuous connectivity
* explicit timeout and retry handling

## 6. Debug and Service Interface

Each Sense Satellite must provide a basic service interface:

* UART or USB for initial provisioning
* firmware flashing and recovery access

No permanent debug interface is required in deployed systems, but access must be possible during development.

## 7. Execution Model (Hardware Perspective)

The hardware design must support the following execution pattern:

1. wake from deep sleep
2. stabilize power and clocks
3. acquire time reference
4. power and read one sensor
5. store measurement
6. optionally transmit data
7. return to deep sleep

No hardware support for concurrency is required.

## 8. Environmental Considerations

Sense Satellite hardware may be deployed in:

* indoor environments
* outdoor enclosures
* mobile systems (e.g. camper vans)

Design considerations:

* condensation protection
* temperature tolerance
* EMI robustness

## 9. Explicit Exclusions

The following are explicitly excluded from this reference design:

* displays
* buttons or user input devices
* local data processing or statistics
* high-current switching
* real-time control loops

## 10. Compliance Statement

A hardware implementation is considered **Sense Satellite compliant** if and only if:

* it is based on ESP32-class MCUs
* ESP32-W1 compatibility is preserved
* all mandatory components defined in this document are present
* forbidden capabilities are not implemented

## 11. Status

This reference design is marked as **Version 0.1**.

It is architecturally complete but open for clarification before being used as the basis for concrete PCB designs.

© Marcel Sauder
