# SENSE System – Nomenclature and Terminology

© Marcel Sauder, 2026

This document defines the official terminology and naming conventions of the SENSE system.  
Its purpose is to clearly separate hardware, firmware, applications, and system-level components in order to avoid conceptual and communicational ambiguity.

This nomenclature is binding for documentation, code, repositories, and future extensions.

## Core Principle

Each architectural layer of the SENSE system has:
– a clearly defined responsibility  
– a unique and unambiguous name  

No term may represent more than one layer.

## Hardware Layer

**SENSE Module**

The SENSE Module is the physical hardware base platform.

Characteristics:
– microcontroller-based device  
– defined sensor and actuator interfaces  
– power management and IO  
– expandable and modular  
– contains no application-specific logic  

The SENSE Module is neutral and not bound to any specific use case.

Examples:
– SENSE Module v1  
– SENSE Module v2  

## Firmware Core Layer

**SENSE Core**

SENSE Core is the fundamental firmware running on the SENSE Module.

Role:
– provides all system-level capabilities  
– manages sensors, actuators, timing, events, storage, and communication  
– contains no application logic  
– is fully controlled via configuration  

SENSE Core is the technical foundation for all applications.

## Application Layer (Profiles)

Applications are consistently named using the **Eco** prefix.

Eco applications define behavior and logic without modifying SENSE Core.

### EcoRoom

Room monitoring and indoor climate sensing.

Typical functions:
– air temperature  
– relative humidity  
– CO₂ concentration  
– trend and time-series evaluation  
– optional local display  
– optional forwarding to SENSE Home  

### EcoFridge

Refrigerator monitoring and control.

Typical functions:
– temperature monitoring  
– compressor control  
– hysteresis logic  
– time-based profiles  
– alarm handling  

Additional Eco applications are explicitly intended, for example:
– EcoAir  
– EcoStorage  
– EcoClimate  

## Operating Modes

Operating modes are configuration states within an Eco application.

They are not separate programs or firmware variants.

Example operating modes for EcoRoom:
– Local Evaluate  
– Forward Only  
– Hybrid Local Display + Forward  

Operating modes are combinations of enabled or disabled SENSE Core capabilities.

## System and Aggregation Layer

**SENSE Home**

SENSE Home is the central software system.

Role:
– aggregation of multiple SENSE Modules  
– long-term data storage  
– evaluation and analytics  
– visualization  
– alarm management  
– optional configuration distribution  

SENSE Home is a software system, not a hardware device.

## Example System Description

A correct and unambiguous system description is:

“A SENSE Module runs SENSE Core using the EcoRoom profile and is connected to SENSE Home.”

This statement clearly distinguishes hardware, firmware, application, and system layers.

## Purpose of This Nomenclature

– avoid ambiguity  
– maintain conceptual clarity  
– support long-term scalability  
– enable clean documentation  
– ensure open-source compatibility  

This nomenclature applies to all current and future components of the SENSE system.
