# SENSE Module – Hardware

© Marcel Sauder, 2026

This document describes the hardware scope, design goals, and structure of the SENSE Module. It defines what the hardware platform is responsible for, what is explicitly out of scope, and how hardware development is organized within the SENSE system.

The hardware is designed to support SENSE Core in full core profile and to serve as a stable foundation for Eco application profiles.

## Purpose of the Hardware Platform

The SENSE Module hardware provides a reliable physical base for:
– environmental sensing
– continuous operation (24/7)
– offline-capable data acquisition
– local data buffering
– optional local visualization
– network connectivity

The hardware is intentionally generic and not bound to a single application.

## Target Platform

SENSE Module hardware version 1 is based on the ESP32 platform.

Rationale:
– sufficient processing power and memory
– stable WiFi operation alongside local storage
– multiple SPI and I²C interfaces
– mature toolchains and ecosystem
– long-term availability

Lower-resource platforms such as ESP8266 are explicitly reserved for SENSE Module Satellite devices and are not considered suitable for the full SENSE Module.

## Hardware Scope (v1)

Included in version 1:
– ESP32-based MCU module
– stable 3.3 V power supply
– optional 5 V input
– I²C bus for environmental sensors
– SPI bus for SD card storage
– optional display interface
– USB or UART for debug and service
– reset and boot access
– status indication (LED)

Not included in version 1:
– high-power switching
– relays or contactors
– motor control
– galvanic isolation
– safety-critical circuits
– battery operation

These features may be addressed in future hardware revisions or external modules.

## Hardware Philosophy

The SENSE Module hardware follows these principles:
– robustness over minimal cost
– clarity over density
– extensibility over specialization
– predictable behavior under fault conditions
– separation of sensing and actuation

The hardware should never encode application logic.

## Relationship to SENSE Core

The hardware is designed to expose capabilities, not decisions.

SENSE Core:
– detects the underlying hardware
– derives its capability set
– enables or disables features accordingly

The same SENSE Core codebase runs on different hardware platforms and adapts its behavior based on detected capabilities.

## Repository Structure

The hardware-related files are organized as follows:

```
hardware/
├── README.md
├── schematics/
├── pcb/
├── bom/
└── mechanical/
```

– schematics: electrical schematics
– pcb: PCB layout files
– bom: bill of materials
– mechanical: mounting, enclosure, and mechanical references

## Versioning Strategy

Hardware revisions are versioned explicitly.

Examples:
– SENSE Module v1.0
– SENSE Module v1.1
– SENSE Module v2.0

Minor revisions address fixes or component changes. Major revisions introduce architectural changes.

## Current Status

The hardware platform is in active development.

Current focus:
– ESP32-based design
– sensor and storage interfaces
– power stability
– preparation for EcoRoom reference deployment

## License

This hardware documentation is released under the GNU General Public License v3.0 (GPL-3.0), unless stated otherwise in specific subdirectories.

See the LICENSE file in the repository root for details.

---

The SENSE Module hardware is designed as a calm, stable foundation. All higher-level system behavior depends on its reliability and clarity.
