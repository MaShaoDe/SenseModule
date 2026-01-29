# 07 Hardware Profile – Sense Satellite

Version: 0.9 (Draft – Functionally Final)
Date: 2026-01-29
Author: Marcel Sauder
Project: SenseModule / SenseCore

## 1. Purpose and Role

The **Sense Satellite** is a strictly measuring and delivering node within the Sense ecosystem. Its sole responsibility is to acquire environmental and system data in a deterministic, serial manner, store this data locally, and optionally deliver it to another node or system.

Sense Satellite nodes are designed to operate unattended, energy-efficient, and optionally fully autonomous. They do not provide user interaction, local visualisation, or on-device analytics.

Sense Satellite is a **role**, not a hardware class. Any SenseCore-compatible hardware may operate in Sense Satellite mode.

## 2. SenseCore Compatibility Contract

A device operating as a Sense Satellite **must fully comply** with the SenseCore compatibility contract. In this role, SenseCore provides:

* deterministic execution
* time-stamped data acquisition
* local, non-volatile data storage
* optional data delivery
* explicit data retention or deletion strategies
* robust recovery and reset behaviour

Sense Satellite does not extend SenseCore. It is a constrained operational mode of it.

## 3. Supported Measurements

A Sense Satellite may acquire the following measurements:

* temperature
* relative humidity
* optional air pressure
* optional wind speed
* optional battery voltage

All measurements are performed **strictly serially**, one after another. No parallel sensor operation is permitted.

Battery voltage measurement is treated as a regular sensor value and may be acquired at a reduced frequency (for example once per hour).

## 4. Execution Model

The execution model is fixed and deterministic:

1. wake from sleep
2. acquire time reference
3. perform a single sensor measurement
4. store measurement locally
5. optionally deliver stored data
6. return to sleep

Wireless communication (Wi-Fi, LoRa, or similar) is event-based and must not remain continuously active.

## 5. Storage and Data Ownership

All measurements **must** be stored in local, non-volatile memory.

* RAM is cache only and must never be considered authoritative
* data delivery is optional
* data deletion is explicit and policy-driven
* default behaviour is to retain data

SD cards are explicitly not required. SPI flash or FRAM are preferred.

## 6. Energy and Autonomy

Sense Satellite nodes may be designed as fully autonomous systems:

* battery powered
* solar powered
* hybrid power systems

Energy availability must not alter SenseCore semantics. Low-energy operation is achieved through sleep cycles, not through functional degradation.

## 7. Forbidden Capabilities

A Sense Satellite **must not** include:

* displays of any kind
* local statistical processing
* user interfaces
* parallel module execution
* continuous wireless connectivity

Any device providing such features must operate in a different Sense role.

## 8. Hardware Compatibility

Sense Satellite nodes are based on **ESP32-class MCUs**.

The following MCU families are supported:

* ESP32 (all variants)
* ESP32-W1 / ESP32-C2 and similar minimal ESP32 derivatives
* ESP32 with integrated LoRa modules

The **ESP32-W1** is defined as the **minimum and reference platform** for Sense Satellite.

## 9. Architectural Implications

Sense Satellite is intentionally minimal. Its simplicity is a feature, not a limitation. By enforcing strict serial execution and local data ownership, Sense Satellite nodes provide:

* predictable power consumption
* high robustness
* offline resilience
* long-term data integrity

## 10. Status

This document is marked as **Version 0.9**.

The functional scope is considered final. Minor clarifications and editorial refinements may follow before promotion to Version 1.0. No functional expansion is planned for this role.

© Marcel Sauder
