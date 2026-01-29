# 10 Hardware Profile – Sense Control Node

Version: 0.9 (Draft – Functionally Final)
Date: 2026-01-29
Author: Marcel Sauder
Project: SenseModule / SenseCore

## 1. Purpose and Role

The **Sense Control Node** is the actuator-capable device within the Sense ecosystem.

Its role is to **apply controlled physical actions** based on configuration, sensor input, and SenseCore-managed state, while preserving the same robustness, determinism, and offline-first guarantees as all other Sense roles.

The Sense Control Node is a **role**, not a specific product. Hardware implementations may vary as long as this profile and the SenseCore Capability Contract are respected.

## 2. Relationship to SenseCore

The Sense Control Node runs **SenseCore in full core role**.

All control behavior is expressed through configuration and enabled capabilities. No application-specific logic is hard-coded into the firmware.

SenseCore remains the single authority for timing, storage, recovery, and communication semantics.

## 3. Core Capabilities

A Sense Control Node must provide the following capabilities:

* local, non-volatile data storage
* deterministic execution and recovery
* time-aware state evaluation
* controlled actuation with explicit state tracking
* optional aggregation of data from Sense Satellites
* optional forwarding to Sense Home or other systems

## 4. Actuation Scope

A Sense Control Node may control:

* low-voltage digital outputs
* relays or solid-state switches
* simple proportional outputs (where explicitly supported)

All actuation must be:

* explicit
* bounded
* reversible where physically possible

## 5. Safety and Constraints

Safety is a first-class concern for Sense Control Nodes.

Mandatory constraints:

* defined default states on boot and reset
* safe fallback behavior on power loss
* explicit limits on actuation duration
* no uncontrolled or oscillatory behavior

Sense Control Nodes must fail **safe**, not fail active.

## 6. User Interaction

User interaction on Sense Control Nodes is optional.

If present, UI elements are subject to the same constraints as Sense Base nodes:

* UI must not be required for correct operation
* UI must not block SenseCore execution
* UI must not bypass configured safety limits

## 7. Processing and Resource Expectations

Sense Control Nodes are based on **ESP32-class MCUs**.

The **ESP32-W1** is the minimum supported platform. More capable ESP32 variants may be used where additional IO, isolation, or safety features are required.

## 8. Storage and State Management

The Sense Control Node follows the same data ownership principles as all Sense roles:

* local non-volatile storage is authoritative
* control state transitions are logged
* recovery after reset must restore a known safe state

## 9. Communication

Communication remains optional and event-driven.

A Sense Control Node may:

* receive control parameters from configuration
* receive sensor data from Sense Satellites
* report actuation state and history

No assumption of continuous connectivity is permitted.

## 10. Forbidden Capabilities

The following are explicitly forbidden:

* safety-critical life-support functions
* hard real-time guarantees
* uncontrolled autonomous learning
* direct cloud-dependent actuation

## 11. Architectural Implications

The Sense Control Node represents the boundary where **digital intent meets physical action**.

This boundary must remain auditable, predictable, and recoverable at all times.

## 12. Status

This document is marked as **Version 0.9**.

The functional scope is considered stable. Minor clarifications may follow before promotion to Version 1.0.

© Marcel Sauder
