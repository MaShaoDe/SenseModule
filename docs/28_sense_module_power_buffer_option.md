# SENSE Module – Power Buffer / Battery Backup Option

© Marcel Sauder, 2026

This document defines an optional power buffer and battery-backup concept for the SENSE Module. The goal is to increase system resilience in environments with unstable power grids, frequent brownouts, or short-term outages, without changing the behaviour of the logic board or the SENSE Core firmware.

This option is strictly additive and never mandatory.

## Purpose

The purpose of the power buffer option is to:
– bridge short power interruptions
– absorb brownouts and short outages
– stabilise supply during grid instability
– protect against sudden power loss during storms or infrastructure failures

It is explicitly not intended to provide long-term autonomous operation.

## Architectural Position

The power buffer is implemented as a **separate power board** placed between the external power source and the SENSE Module logic board.

Architecture:
– external supply (DC 12 V or AC-derived 12 V)
– power buffer board
– SENSE Module logic board (12 V input)

The logic board is completely unaware of whether a buffer is present.

## Design Principles

The power buffer option follows these principles:
– strict separation from logic electronics
– no firmware dependency or power-state awareness
– transparent pass-through during normal operation
– automatic takeover during power loss
– predictable and fail-safe behaviour

The buffer must never alter nominal operating voltage under normal conditions.

## Functional Concept

### Normal Operation

– external 12 V supply powers the system
– power is passed directly to the logic board
– battery is maintained at charge level
– no switching activity in the logic supply path

### Power Loss or Brownout

– external supply drops or becomes unstable
– power buffer automatically supplies 12 V output
– logic board continues operation without reset
– system behaviour remains unchanged

### Power Return

– external supply resumes
– buffer disengages seamlessly
– battery recharge resumes under controlled conditions

## Battery Technology

Permitted battery types:
– lithium-ion 18650 cells
– protected cells only
– use of dedicated holders or enclosed packs

Configuration:
– one or more cells, depending on required buffer time
– capacity dimensioned for minutes, not hours

Unprotected cells are explicitly forbidden.

## Charging and Protection

Mandatory charging and protection features:
– dedicated charge controller
– overcharge protection
– overdischarge protection
– overcurrent protection
– temperature monitoring

All battery management functions must be handled entirely on the power buffer board.

## Electrical Behaviour

The buffer board must provide:
– stable 12 V output
– no voltage overshoot during switching
– no backfeeding into external supplies
– no undefined intermediate states

Ideal-diode or power-multiplexer concepts are preferred.

## Explicit Non-Goals

The power buffer option is not intended to:
– replace an uninterruptible power supply (UPS)
– support long-term battery-only operation
– provide graceful shutdown functionality
– expose battery status to the logic board
– introduce new firmware states or modes

## Safety Considerations

Battery-based power buffering introduces additional risks.

Therefore:
– batteries must be physically separated from logic electronics
– thermal considerations must be addressed
– ventilation and spacing must be adequate
– only proven charging ICs and protection circuits may be used

## Relationship to Other Documents

This document extends:
– docs/26_sense_module_power_design_overview.md
– docs/27_sense_module_power_variants_and_protection.md
– docs/24_sense_module_schematic_design_guidelines.md

## Summary

The power buffer option increases robustness of the SENSE Module in unstable power environments.

By implementing battery buffering as a transparent, optional power board with no firmware dependency, the system gains resilience without sacrificing architectural clarity or safety.
