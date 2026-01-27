# SENSE Module – Pin and Bus Strategy

© Marcel Sauder, 2026

This document defines the pin usage principles and bus strategy for SENSE Module hardware version 1. It establishes rules for how interfaces are allocated, reserved, and protected in order to ensure long-term maintainability and extensibility.

The goal is not to assign final pin numbers, but to define a clear strategy that guides schematic and PCB design.

## Purpose

The pin and bus strategy ensures that:
– core functionality is stable
– future extensions remain possible
– conflicts between peripherals are avoided
– debugging and recovery remain accessible

## General Principles

The following principles apply to all pin and bus decisions:

– never fully exhaust available GPIOs
– reserve pins for future use
– keep buses functionally separated
– avoid pin assignments that restrict boot or flashing
– prefer simplicity over maximal density

## MCU Reference

The SENSE Module uses an ESP32-WROOM family module.

All pin planning must respect:
– ESP32 boot strapping pins
– flash and internal peripheral usage
– documented Espressif constraints

## I²C Bus Strategy

Primary I²C Bus:
– dedicated to environmental sensors
– temperature, humidity, CO₂
– fixed bus speed
– external pull-ups provided on board

Secondary I²C Bus (optional):
– reserved for future extensions
– display or auxiliary sensors
– may share pins if not populated

Rules:
– no hardwired sensor addresses assumed
– address conflicts must be resolvable
– bus length kept short and predictable

## SPI Bus Strategy

The SPI bus is divided logically by function.

SPI Bus A:
– microSD card
– dedicated chip select
– highest priority for signal integrity

SPI Bus B (optional or shared):
– display interface
– lower throughput requirements

Rules:
– SD card and display must not share chip select
– SD card must have priority
– SPI pins must not overlap with boot-critical pins

## Storage Interface

Primary storage:
– microSD card via SPI

Design rules:
– card detect optional
– write-protect handled in software
– SD interface must remain functional during WiFi activity

## Display Interface

Display support is optional.

Design rules:
– interface selectable (SPI or I²C)
– backlight control optional
– absence of display must not affect system operation

Display pins must be fully ignorable by firmware if no display is present.

## Debug and Service Pins

Mandatory debug access:
– UART TX/RX
– reset
– boot mode selection

Rules:
– debug pins must be accessible without removing the PCB
– boot pins must not be overloaded
– serial console must remain usable even in fault states

## Status Indicators

Status LED:
– single multi-purpose LED
– controlled by firmware
– used for boot, error, and activity indication

LED pin must not interfere with boot or flash operation.

## Reserved Pins

The following must be reserved:
– at least two GPIOs for future expansion
– one GPIO for potential interrupt-based sensors

Reserved pins must not be assigned in version 1 schematics.

## Interaction with SENSE Core

SENSE Core relies on predictable interface availability.

The firmware:
– detects available peripherals
– enables or disables features dynamically
– never assumes optional hardware is present

Hardware must support this detection model.

## Non-Goals

This document does not define:
– exact pin numbers
– component footprints
– signal routing details
– PCB layout rules

These are addressed in schematics and PCB design phases.

## Relationship to Other Documents

This strategy builds upon:
– docs/20_sense_module_block_diagram.md
– docs/21_esp32_module_selection.md
– hardware/README.md

## Summary

The pin and bus strategy defines a disciplined approach to interface allocation. By prioritizing clarity, reservation, and separation, it ensures that SENSE Module v1 remains extensible and debuggable throughout its lifecycle.
