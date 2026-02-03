# SENSE Module Satellite – Overview

© Marcel Sauder, 2026

This document defines the role, scope, hardware platform, and form factor decisions for the SENSE Module Satellite. It provides a clear and explicit distinction between the Satellite and the primary SENSE Module and documents all constraints relevant for hardware and firmware design.

This document supersedes any implicit assumptions regarding ESP8266 usage or form factor selection.

## Purpose

The SENSE Module Satellite exists to provide reliable, low-cost, distributed sensing capabilities within the SENSE ecosystem.

Its primary purpose is to:
– measure a small, well-defined set of parameters
– attach clear device and sensor identification
– timestamp measurements
– buffer data temporarily if required
– forward data reliably to a SENSE Module

The Satellite is intentionally not capable of independent operation or semantic evaluation.

## Position in the SENSE Architecture

The Satellite occupies a strictly subordinate and supportive role.

– SENSE Module (ESP32): aggregation, evaluation, decision-making
– SENSE Module Satellite (ESP8266): sensing and forwarding
– SENSE Home: long-term storage, visualization, alarms

Satellites never communicate directly with SENSE Home and never execute Eco application profiles.

## Hardware Platform Selection

The SENSE Module Satellite is based on the ESP8266 platform.

Rationale:
– sufficient processing capability for simple sensing tasks
– integrated WiFi
– low cost
– compact form factor
– mature and well-understood ecosystem

The ESP8266 is used exclusively for Satellite devices and is not used in the primary SENSE Module.

## Firmware and SENSE Core Profile

The Satellite runs the same SENSE Core codebase as the SENSE Module.

At boot time, SENSE Core detects the underlying hardware platform.

– ESP8266: satellite core profile enforced
– ESP32: full core profile permitted

The satellite core profile disables all functionality not required for sensing and forwarding.

## Satellite Core Profile Capabilities

Enabled:
– device identity and metadata
– sensor acquisition
– timestamping
– structured data packet creation
– minimal local buffering
– reliable forwarding with acknowledgement
– resend after reconnect

Disabled:
– Eco application profiles
– semantic evaluation
– event classification
– local display
– actuator control
– direct SENSE Home integration

## Development Board Form Factor Decision

ESP8266 development boards are commonly available in different pin-count variants.

### 32-Pin ESP8266 Dev Board

Characteristics:
– sufficient GPIOs for limited sensing tasks
– compact footprint
– low cost
– minimal complexity

Assessment:
The 32-pin ESP8266 form factor provides adequate resources for the Satellite role without unnecessary overhead. It aligns with the design philosophy of simplicity, replaceability, and cost efficiency.

### Larger ESP8266 Form Factors

Characteristics:
– increased GPIO availability
– larger physical footprint
– higher cost

Assessment:
Larger ESP8266 form factors do not provide meaningful advantages for the Satellite use case and would contradict the intended minimalism of the device.

### Final Form Factor Decision

**SENSE Module Satellite SHALL be based on a 32-pin ESP8266 development board.**

Larger ESP8266 form factors are explicitly excluded for Satellite devices.

## Typical Use Cases

Typical Satellite deployments include:
– individual refrigerators in multi-unit installations
– remote or hard-to-access measurement points
– distributed sensing networks
– cost-sensitive monitoring scenarios

Multiple Satellites may forward data to a single SENSE Module.

## Design Philosophy

The SENSE Module Satellite is designed to be:
– simple
– predictable
– inexpensive
– easily replaceable
– operationally robust

Feature growth is explicitly discouraged.

## Relationship to Future Hardware

The SENSE Module Satellite is defined as a separate hardware project.

It will have:
– its own hardware repository
– its own hardware README
– its own block diagram and schematics

Despite this separation, it remains fully aligned with the SENSE ecosystem through SENSE Core and shared data models.

## Relationship to Other Documents

This document builds upon:
– docs/20_sense_module_block_diagram.md
– docs/21_esp32_module_selection.md
– docs/22_sense_module_pin_and_bus_strategy.md
– docs/24_sense_module_schematic_design_guidelines.md

## Summary

The SENSE Module Satellite is a focused sensing node within the SENSE system.

By explicitly defining its role, hardware platform, and form factor, the architecture ensures scalability, clarity, and long-term maintainability while avoiding unnecessary complexity.
