# SENSE Hardware Variants

© Marcel Sauder, January 2026

This document defines the hardware structure of the SENSE ecosystem. It describes the base hardware platform and the concept of optional hardware modules used to create different device configurations.

The goal is to provide a **single, stable hardware foundation** that can support all operating modes and Eco applications without fragmenting firmware or system architecture.

## Core Principle

The SENSE ecosystem is built around **one base hardware platform**.

Hardware differences do not create different device types. Instead, different device configurations are composed from:
– a common baseboard
– optional hardware modules
– configuration and operating modes

All SENSE devices:
– run the same SENSE Core firmware
– support the same operating modes
– follow the same configuration model

## SENSE Baseboard

The SENSE Baseboard is the mandatory foundation of every SENSE Module.

It provides all hardware capabilities required to run any operating mode and any Eco application.

### Responsibilities of the Baseboard

The Baseboard is responsible for:
– executing SENSE Core
– providing stable power and timing
– interfacing sensors
– buffering and forwarding data
– exposing defined expansion interfaces

The Baseboard is intentionally **neutral**. It is not optimized for any specific use case.

### Typical Components on the Baseboard

A SENSE Baseboard typically includes:
– microcontroller (ESP32 class)
– real-time clock or equivalent time source
– external non-volatile storage (e.g. SPI Flash)
– regulated 3.3 V power supply
– sleep-capable power architecture
– sensor buses (e.g. I²C, 1-Wire)
– communication interfaces
– reset, boot, and status indicators

### What Does Not Belong on the Baseboard

To keep the base hardware clean and reusable, the following elements are intentionally excluded from the Baseboard:
– batteries or battery holders
– battery management systems (BMS)
– solar charge controllers
– high-current switching elements
– relays or power drivers
– displays or user interfaces
– application-specific peripherals

These elements are provided through optional modules.

## Optional Hardware Modules

Optional hardware modules extend the capabilities of the Baseboard.

Modules are:
– electrically and logically independent
– optional
– interchangeable
– not required for core functionality

Removing or adding a module must not require firmware changes.

### Display Module

Purpose:
– local visualization of measurements
– device status display
– debugging support

Characteristics:
– connected via I²C or SPI
– passive and stateless
– no application logic

Typical use cases:
– wall-mounted thermometers
– room monitoring devices
– status displays

### Control Module

Purpose:
– switching or controlling external devices
– providing actuator interfaces

Typical components:
– relays or solid-state relays
– protection circuitry
– optional galvanic isolation

Typical use cases:
– EcoFridge control
– simple automation tasks
– controlled power switching

The Control Module provides hardware capabilities only. Control logic remains within Eco applications.

### Power Module (Battery / Solar)

Purpose:
– off-grid operation
– battery-powered systems
– solar-powered systems

Typical components:
– 18650 battery holder
– battery management system
– charging controller
– solar input
– optional voltage regulation

Typical use cases:
– outdoor temperature satellites
– remote sensing nodes
– energy-autonomous devices

The Power Module is optional and not required for mains-powered installations.

### Communication Modules

Communication capabilities may be provided either by the Baseboard or by optional modules.

Examples:
– WiFi communication
– LoRa communication

Communication modules:
– implement physical data transmission
– expose a unified interface to SENSE Core
– do not affect operating mode semantics

## Device Configurations

Different SENSE devices are created by combining the Baseboard with optional modules and configuration.

Examples:
– Indoor room sensor: Baseboard + Display Module + WiFi
– Outdoor temperature satellite: Baseboard + Power Module + LoRa
– Refrigerator controller: Baseboard + Control Module + WiFi

All configurations:
– use the same firmware
– use the same operating modes
– differ only in hardware population and configuration

## Summary

The SENSE hardware architecture is based on:
– one stable baseboard
– optional, composable hardware modules
– configuration-driven behavior

This approach ensures long-term maintainability, scalability, and architectural clarity across all SENSE deployments.
