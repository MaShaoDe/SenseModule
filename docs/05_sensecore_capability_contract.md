# 05 SenseCore Capability Contract

Version: 0.9 (Draft – Structurally Final)
Date: 2026-01-29
Author: Marcel Sauder
Project: SenseModule / SenseCore

## 1. Purpose

This document defines the **capability contract** of SenseCore.

It specifies which guarantees SenseCore provides to hardware, application profiles, and higher-level systems, and which assumptions are explicitly **not allowed**.

The SenseCore Capability Contract is binding for all Sense roles, including:

* Sense Satellite
* Sense Base / Display Node
* Sense Control Node

## 2. Scope

SenseCore is a **role-agnostic kernel**.

It does not implement application logic, user interfaces, or domain-specific semantics. It provides a stable, minimal, and deterministic foundation upon which all Sense roles are built.

This contract applies independently of the underlying ESP32-class MCU variant.

## 3. Core Guarantees

SenseCore guarantees the following capabilities:

### 3.1 Deterministic Execution

* a clearly defined execution cycle
* predictable wake, run, and sleep phases
* no implicit concurrency assumptions
* no hidden background tasks

### 3.2 Time Handling

* time-stamped data acquisition
* explicit time source management
* tolerance for intermittent or delayed synchronization
* monotonic internal time progression

### 3.3 Data Ownership and Storage

* local, non-volatile storage as the single source of truth
* RAM used only as transient cache
* explicit data lifecycle states (stored, delivered, retained, deleted)
* no implicit data loss

### 3.4 Communication

* communication is optional and event-based
* delivery success and failure are explicit states
* retry logic is bounded and deterministic
* no permanent connectivity assumptions

### 3.5 Power Awareness

* power availability is treated as a variable, not a constant
* deep sleep is a first-class execution state
* no requirement for continuous power

### 3.6 Recovery and Robustness

* watchdog integration
* deterministic reboot behavior
* safe handling of partial failures
* no undefined states after reset

## 4. Explicit Non-Guarantees

SenseCore explicitly does **not** guarantee:

* real-time hard deadlines
* continuous network connectivity
* uninterrupted power availability
* high-frequency sampling
* concurrent multi-task execution

Any system assuming such properties is outside the Sense architecture.

## 5. Role Interaction

SenseCore itself is unaware of roles.

Roles such as Sense Satellite or Sense Base are defined by **configuration and enabled capabilities**, not by branching code paths or separate kernels.

## 6. Forbidden Assumptions

The following assumptions are forbidden in any SenseCore-dependent component:

* availability of a display
* availability of user input
* presence of a specific sensor
* continuous network access
* infinite storage

Violating these assumptions constitutes an architectural error.

## 7. Stability and Evolution

SenseCore is intentionally conservative.

New capabilities may be added, but existing guarantees must not be weakened. Backward compatibility at the contract level is mandatory.

## 8. Status

This document is marked as **Version 0.9**.

The structure and guarantees are considered stable. Minor clarifications may follow before promotion to Version 1.0.

© Marcel Sauder
