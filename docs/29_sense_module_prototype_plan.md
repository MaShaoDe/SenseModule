# SENSE Module – Prototype and Validation Plan

© Marcel Sauder, 2026

This document defines the prototyping and validation strategy for the SENSE Module. It formalises the decision to validate real components and real system behaviour before committing to a custom PCB design.

The goal is to reduce technical risk, avoid premature optimisation, and ensure that the final hardware reflects proven behaviour rather than assumptions.

## Purpose

The purpose of this prototype plan is to:
– define a structured, step-by-step prototyping approach
– validate real hardware components and interactions
– support parallel firmware development
– establish clear exit criteria for PCB design

This document explicitly prioritises learning and validation over speed.

## Guiding Principles

The prototyping phase follows these principles:
– test real components, not datasheet abstractions
– prefer observable behaviour over theoretical correctness
– expose edge cases early
– avoid PCB commitment until uncertainties are resolved
– keep the system architecture intact during testing

## Scope of the Prototype

The prototype covers the following subsystems:
– SENSE Module logic core (ESP32)
– sensor subsystem (temperature, humidity, CO₂)
– timekeeping (RTC with backup battery)
– storage (SD card)
– user interface elements (display, status indicators)
– power input via conditioned 12 V

Excluded from the prototype phase:
– custom PCB layout
– enclosure design
– regulatory certification work
– production optimisation

## Phase 1 – Component Fixation

Goal:
– identify which concrete modules and sensors are used for v1

Activities:
– list available RTC modules
– list temperature and humidity sensors
– list CO₂ sensor models and interfaces
– list display modules and resolutions
– list storage modules (SD)
– verify electrical compatibility (3.3 V logic)

Output:
– preliminary component list v1
– rejected components documented implicitly by absence

## Phase 2 – Laboratory Prototype Setup

Goal:
– build a functional laboratory prototype using existing modules

Activities:
– assemble components on breadboard or modular wiring
– use ESP32 dev board as logic core
– supply system via 12 V input and step-down regulation
– avoid USB-powered operation
– ensure shared ground and clean wiring

Focus areas:
– I²C bus stability with multiple devices
– SPI coexistence (display, SD card)
– sensor timing and update intervals
– power-up and reset behaviour

## Phase 3 – Power Behaviour Validation

Goal:
– validate system behaviour under imperfect power conditions

Activities:
– introduce brownouts
– simulate short power interruptions
– observe reboot and recovery behaviour
– monitor voltage stability during WiFi activity
– verify RTC continuity

This phase validates assumptions made in Docs/26–28.

## Phase 4 – Parallel Firmware Development

Goal:
– develop and validate SENSE Core functionality on real hardware

Activities:
– initialise core runtime
– integrate sensor drivers
– test configuration handling
– implement local buffering (SD)
– validate error handling and recovery paths

Firmware development runs in parallel with Phases 2 and 3.

## Phase 5 – Integration Validation

Goal:
– validate subsystem interaction under realistic conditions

Activities:
– simultaneous sensor operation
– display updates during logging
– SD writes under load
– long-duration runtime tests
– forced fault scenarios

## Exit Criteria for PCB Design

The transition to PCB design is permitted only when:
– component list v1 is stable
– pin assignments are validated
– power behaviour is predictable
– no unresolved bus conflicts remain
– firmware runs reliably on the prototype

These criteria must be met before schematic capture begins.

## Relationship to Other Documents

This document builds upon:
– docs/20_sense_module_block_diagram.md
– docs/26_sense_module_power_design_overview.md
– docs/27_sense_module_power_variants_and_protection.md
– docs/28_sense_module_power_buffer_option.md

## Summary

The SENSE Module prototype phase establishes confidence through validation.

By testing real components in realistic conditions and developing firmware in parallel, the project avoids premature hardware commitment and enables a calm, controlled transition to PCB design.
