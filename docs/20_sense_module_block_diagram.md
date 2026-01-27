# SENSE Module – Block Diagram v1

© Marcel Sauder, 2026

This document defines the high-level block diagram of the SENSE Module hardware version 1. It describes functional blocks, data paths, and power domains without committing to specific components or pin assignments.

The block diagram serves as the bridge between conceptual documentation and electrical schematics.

## Purpose

The purpose of this block diagram is to:
– clarify hardware responsibilities
– define interfaces and buses
– identify mandatory and optional blocks
– prevent premature schematic decisions
– provide a shared reference for hardware and firmware development

## Overview

The SENSE Module is a modular ESP32-based device designed to run SENSE Core in full core profile. It supports environmental sensing, local buffering, optional display output, and reliable network communication.

The architecture is centered around a single MCU with clearly separated power, sensing, storage, and communication domains.

## Functional Blocks

### Power Supply Block

Responsibilities:
– accept external power input
– generate stable internal voltages
– protect against brownout and instability

Structure:
– external power input (5 V nominal)
– voltage regulation to 3.3 V
– bulk and decoupling capacitors
– power-on reset and brownout detection

Notes:
– battery operation is explicitly out of scope for v1
– power stability has priority over efficiency

## MCU Block

Core component:
– ESP32 MCU module

Responsibilities:
– execute SENSE Core
– manage all peripherals
– handle networking and storage concurrently

Key interfaces:
– GPIO
– I²C
– SPI
– UART or USB

The ESP32 is detected by SENSE Core at boot time and enables the full capability set.

## Sensor Interface Block

Purpose:
– connect environmental sensors

Structure:
– primary I²C bus
– optional secondary I²C bus or selectable addressing
– pull-up resistors controlled by hardware configuration

Typical sensors:
– temperature
– humidity
– CO₂

Notes:
– sensor modules are external and replaceable
– no sensor is hardwired

## Local Storage Block

Purpose:
– offline buffering of measurement data

Structure:
– microSD card interface
– SPI connection to MCU

Responsibilities:
– store structured data packets
– support sequential resend after reconnect

Notes:
– SD card is optional but strongly recommended
– storage behavior is managed entirely by SENSE Core

## Display Interface Block (Optional)

Purpose:
– local visualization of sensor data and system state

Structure:
– SPI or I²C interface
– optional backlight control

Notes:
– display presence is auto-detected
– system operates fully without a display
– no display logic is embedded in hardware

## Communication Block

Purpose:
– external data communication

Structure:
– WiFi via ESP32 integrated radio
– optional wired debug interface

Responsibilities:
– data forwarding to SENSE Home
– reception of acknowledgements
– connection health monitoring

Notes:
– communication loss must not affect data acquisition

## Debug and Service Block

Purpose:
– development, diagnostics, and recovery

Structure:
– UART or USB interface
– reset button
– boot mode selection
– status LED

Notes:
– all service interfaces must be accessible without disassembly

## Logical Data Flow

Sensor data flow:
– sensors → MCU → local storage → network

Control flow:
– configuration → SENSE Core → capability management

Offline behavior:
– data stored locally
– network reconnect detected
– stored data resent
– confirmed data deleted

## Explicit Non-Goals

The following are intentionally excluded from this block diagram:
– actuator outputs
– relays or high-current paths
– galvanic isolation
– motor control
– safety-certified circuits

These features are reserved for future modules or extensions.

## Relationship to Other Documents

This block diagram builds upon:
– docs/00_nomenclature.md
– docs/01_sense_core_overview.md
– hardware/README.md

Subsequent documents will refine this diagram into:
– concrete component selection
– pin assignment
– electrical schematics

## Summary

The SENSE Module block diagram defines a calm, modular hardware structure. It ensures that sensing, storage, communication, and power domains are clearly separated while remaining tightly integrated through SENSE Core.

All detailed hardware design work must remain consistent with this block diagram.
