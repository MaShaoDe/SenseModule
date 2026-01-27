# SENSE Module – Power Design Overview

© Marcel Sauder, 2026

This document defines the power design philosophy and high-level power architecture for the SENSE Module hardware version 1. It focuses on stability, robustness, and predictable behaviour under real-world conditions.

The power system is treated as a critical infrastructure component. Reliability and protection take precedence over convenience, minimal cost, or compactness.

## Purpose

The purpose of this document is to:
– define power-related design goals
– establish clear architectural boundaries
– describe supported and unsupported approaches
– guide schematic and PCB decisions
– prevent later reintroduction of unstable solutions

## Core Design Principles

The power design of the SENSE Module follows these principles:
– long-term stable operation over optimisation
– tolerance against poor or unstable external supplies
– strict separation of power handling and logic
– predictable behaviour during brownouts and outages
– protection against electrical abuse and transients

## Supported Power Philosophy

The SENSE Module logic board is designed to operate from a **single, well-defined input domain**.

– primary input to the logic board: **12 V DC**
– all lower voltages are generated locally
– the logic board never interfaces directly with mains voltage

This approach ensures consistent behaviour across all deployment scenarios.

## Explicit Exclusion of 5 V / USB Power

Powering the SENSE Module directly from 5 V or USB-based adapters is explicitly excluded.

Reasons for exclusion:
– highly inconsistent power quality on the consumer market
– widespread use of low-quality, poorly regulated adapters
– insufficient transient response during WiFi load peaks
– susceptibility to voltage dips, overshoot, and HF noise
– increased risk of undefined MCU behaviour and data corruption
– realistic risk of permanent hardware damage due to spikes

USB-based power solutions are therefore considered unsuitable for a reliable sensing platform and are not supported.

## Separation of Power and Logic

Power handling and power conversion must be separated from the logic board.

– input conditioning and primary protection occur before the logic board
– logic board receives conditioned 12 V only
– no high-risk power circuitry on the logic board

This separation improves safety, EMC behaviour, maintainability, and fault isolation.

## Voltage Domains

The SENSE Module uses the following voltage domains:

– external supply domain (DC or AC-derived)
– internal 12 V logic input domain
– internally generated 5 V domain (if required)
– regulated 3.3 V domain for all digital logic

All digital components operate exclusively at 3.3 V.

## Regulation Strategy

The preferred regulation strategy is conservative and explicit:

– step-down regulation from 12 V to 5 V (optional)
– final regulation from 5 V or 12 V to 3.3 V
– generous current headroom
– thermal margins prioritised over efficiency

Switching or linear regulators may be used depending on noise and thermal requirements.

## Brownout and Reset Behaviour

The power architecture must guarantee:
– clean power-on reset
– controlled reset during brownouts
– no undefined intermediate states

Reset behaviour must be explicitly designed and must not rely on MCU defaults alone.

## Interaction with SENSE Core

SENSE Core assumes:
– abrupt power loss is possible
– no graceful shutdown is guaranteed
– storage operations may be interrupted

Data integrity is handled at the software level. Hardware must provide stable supply behaviour but must not encode power-state logic.

## Relationship to Other Documents

This document is complemented by:
– docs/27_sense_module_power_variants_and_protection.md
– docs/25_sense_module_schematics_overview.md
– docs/24_sense_module_schematic_design_guidelines.md

## Summary

The SENSE Module power design prioritises calm, predictable operation in imperfect environments.

By enforcing a 12 V logic input, excluding unreliable supply methods, and separating power handling from logic, the architecture achieves long-term robustness and operational safety.
