# Decision Log – MCU Baseline

Decision ID: DL-001
Date: 2026-01-29
Author: Marcel Sauder
Project: SenseModule / SenseCore

## Decision

The SenseModule project standardizes on **ESP32-class microcontrollers** as the exclusive MCU baseline for all Sense hardware.

The **ESP32-W1** is defined as the minimum and reference platform.

MCU families outside the ESP32 class, including ESP8266, are explicitly excluded from current and future SenseModule designs.

## Context

Early architectural exploration considered multiple MCU families in order to evaluate cost, power consumption, and minimal hardware configurations.

During system consolidation, it became clear that supporting multiple MCU classes introduced unnecessary complexity, reduced robustness, and increased long-term maintenance risk.

## Rationale

The ESP32-class MCU baseline was chosen for the following reasons:

* significantly larger and more predictable memory headroom
* robust and maintainable OTA update mechanisms
* improved networking stability
* better error recovery and watchdog behavior
* consistent hardware abstraction across all Sense roles
* long-term availability and ecosystem stability

The ESP32-W1 provides the optimal balance between minimal hardware footprint and sufficient system reserves.

## Consequences

* All Sense hardware designs are ESP32-based
* Sense Satellite remains a constrained role, not a reduced MCU class
* Firmware, tooling, and documentation are simplified
* Future feature growth does not require architectural rework

## Status

Accepted and binding.

This decision is considered foundational and is not expected to change without a major architectural revision.

© Marcel Sauder
