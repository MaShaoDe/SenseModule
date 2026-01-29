# 09 Hardware Profile – Sense Base / Display Node

Version: 0.9 (Draft – Functionally Final)
Date: 2026-01-29
Author: Marcel Sauder
Project: SenseModule / SenseCore

## 1. Purpose and Role

The **Sense Base / Display Node** is the primary human-facing device within the Sense ecosystem.

Its role is to provide **local visibility, interaction, and contextual feedback** while remaining fully compliant with the SenseCore capability contract. The Sense Base aggregates data, presents information locally, and may act as an uplink or coordination node for one or more Sense Satellites.

The Sense Base is a **role**, not a specific product. Hardware implementations may vary as long as this profile is respected.

## 2. Relationship to SenseCore

The Sense Base runs **SenseCore in full core role**.

It does not embed application logic directly. All higher-level behavior is defined through configuration and enabled capabilities, such as Eco application profiles.

The Sense Base may expose more capabilities than a Sense Satellite, but it must not violate any SenseCore guarantees or assumptions.

## 3. Core Capabilities

A Sense Base must provide the following core capabilities:

* local, non-volatile data storage
* deterministic execution and recovery
* time-aware data handling
* optional aggregation of data from Sense Satellites
* optional forwarding to Sense Home or external systems

## 4. User Interface and Interaction

Unlike Sense Satellite nodes, the Sense Base **may provide user interaction**.

Permitted UI elements include:

* displays (e-paper, LCD, OLED)
* minimal physical input (buttons, rotary encoders)
* touch input (optional)

UI characteristics:

* UI is informational and configurational
* UI must not be required for correct system operation
* system must remain functional without UI interaction

## 5. Display Scope and Constraints

Displays on Sense Base nodes may present:

* current sensor values
* historical summaries and simple statistics
* system status and health indicators
* configuration feedback

Explicit constraints:

* UI must not assume continuous user presence
* display refresh rates must respect power constraints
* UI must not block SenseCore execution

## 6. Processing and Resource Expectations

Sense Base nodes are expected to run on **ESP32-class MCUs** with sufficient resources for:

* SenseCore full role execution
* UI rendering
* buffering and aggregation

The **ESP32-W1** remains the minimum supported platform. More capable ESP32 variants may be used when UI or aggregation complexity increases.

## 7. Storage and Data Ownership

The Sense Base follows the same data ownership principles as all Sense roles:

* local storage is authoritative
* data delivery is explicit
* data retention policies are configurable

Sense Base nodes may retain longer histories than Sense Satellites but must not assume infinite storage.

## 8. Communication

A Sense Base may support multiple communication paths:

* Wi-Fi (primary)
* wired serial or bus connections (optional)
* communication with multiple Sense Satellites

Communication remains event-driven and explicit. Continuous connectivity is not assumed.

## 9. Forbidden Capabilities

The following are explicitly forbidden, even on Sense Base nodes:

* hard real-time guarantees
* safety-critical control loops
* implicit cloud dependency
* blocking UI-driven execution paths

## 10. Architectural Implications

The Sense Base represents the **boundary between autonomous sensing and human interpretation**.

It must remain robust, predictable, and offline-capable, even when UI elements are present or unavailable.

## 11. Status

This document is marked as **Version 0.9**.

The functional scope is considered stable. Minor clarifications may follow before promotion to Version 1.0.

© Marcel Sauder
