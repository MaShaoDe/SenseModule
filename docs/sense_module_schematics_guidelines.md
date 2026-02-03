# SENSE Module – Schematic Design Guidelines

© Marcel Sauder, 2026

This document defines schematic design rules and conventions for the SENSE Module hardware. It provides guidance for creating electrical schematics that are consistent, readable, and aligned with the architectural decisions of the SENSE system.

The intent is to ensure that schematics remain understandable, reviewable, and maintainable over the full lifecycle of the project.

## Purpose

These guidelines exist to:
– enforce architectural consistency
– prevent accidental design regressions
– improve readability and reviewability
– support long-term maintenance and revisioning
– provide a shared reference for contributors

## Scope

These rules apply to:
– SENSE Module v1 schematics
– all subsequent SENSE Module revisions

They do not apply to:
– SENSE Module Satellite schematics
– external expansion boards
– purely mechanical drawings

## General Schematic Principles

– one functional block per schematic page
– clear signal flow from left to right
– power at the top, ground at the bottom
– avoid crossing wires whenever possible
– name all nets explicitly
– avoid implicit connections

Schematics should prioritize clarity over compactness.

## Power Domain Conventions

– clearly separate power input, regulation, and distribution
– label all power rails explicitly (e.g. +5V, +3V3)
– decoupling capacitors must be shown near consumers
– bulk capacitors must be placed near regulators
– ground symbols must be consistent

Brownout protection and reset circuitry must be clearly visible.

## MCU Representation

– the ESP32 module must be represented as a single logical block
– internal pins not used must be explicitly marked as NC
– boot strapping pins must be clearly labeled
– flash and antenna-related notes must be included

Do not split the MCU across multiple schematic pages.

## Bus Representation

### I²C

– show SDA and SCL clearly
– indicate pull-up resistors explicitly
– label bus name consistently (e.g. I2C_MAIN)
– avoid mixing unrelated devices on the same page

### SPI

– show SCLK, MOSI, MISO, CS explicitly
– each CS line must be uniquely labeled
– SD card and display must be visually separated

## Storage Interface

– SD card circuitry must be isolated on its own page
– include ESD protection if applicable
– card detect pins must be labeled even if unused

## Display Interface

– display circuitry must be optional
– clearly mark display signals as optional
– do not assume display presence in the schematic

## Debug and Programming Interfaces

– UART TX/RX must be clearly labeled
– reset and boot controls must be shown explicitly
– programming interface must be accessible without removing components

## Status Indicators

– LEDs must include current-limiting resistors
– LED purpose must be documented (status, error, activity)

## Net Naming Conventions

– use descriptive net names
– avoid generic names like NET1, SIGNAL_A
– keep naming consistent across pages

## Annotation and Documentation

– each schematic page must have a title
– revision number and date must be included
– important design decisions must be annotated
– assumptions and limitations should be documented

## Design Review Checklist

Before finalizing a schematic:
– all power rails labeled
– all optional components marked
– all buses named consistently
– all NC pins marked
– boot pins verified
– reset behavior validated
– debug access confirmed

## Relationship to Other Documents

These guidelines build upon:
– docs/20_sense_module_block_diagram.md
– docs/21_esp32_module_selection.md
– docs/22_sense_module_pin_and_bus_strategy.md
– hardware/README.md

## Summary

The schematic design guidelines define a disciplined approach to electrical design. By emphasizing clarity, separation of concerns, and explicit documentation, they ensure that SENSE Module hardware remains understandable, reviewable, and extensible throughout its lifecycle.
