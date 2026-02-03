# SENSE Core – Firmware Core Overview

© Marcel Sauder, 2026

This document defines the scope, responsibilities, and architectural principles of SENSE Core.  
SENSE Core is the foundational firmware layer of the SENSE system and runs on the SENSE Module hardware platform.

It is intentionally application-agnostic and fully configuration-driven.

## Purpose of SENSE Core

SENSE Core provides all system-level capabilities required to operate a SENSE Module.

It does not implement any specific application logic such as room monitoring or refrigerator control.  
All application behavior is defined by Eco profiles via configuration.

## Design Principles

SENSE Core is built around the following principles:

– clear separation between core functionality and applications  
– deterministic and predictable behavior  
– offline-first operation  
– configuration over code changes  
– modular and extensible architecture  
– robustness over feature density  

## Responsibilities of SENSE Core

SENSE Core is responsible for the following domains.

### Device Identity and Metadata

– unique device identification  
– firmware versioning  
– hardware capability reporting  
– basic self-description  

### Sensor Management

– abstract sensor interfaces  
– unified sampling model  
– configurable sampling intervals  
– sensor health and availability checks  

SENSE Core does not interpret sensor meaning.  
It only provides reliable data acquisition.

### Actuator Management

– abstract actuator interfaces  
– safe default states  
– controlled execution of actuator commands  

Actual control logic is defined by Eco applications.

### Time and Scheduling

– system time handling  
– periodic task scheduling  
– delayed execution  
– time-based triggers  

SENSE Core does not define what is scheduled, only how scheduling works.

### Event and State Handling

– internal state tracking  
– event generation  
– event propagation to applications  
– severity classification  

SENSE Core generates events but does not decide their semantic meaning.

### Data Handling and Storage

– structured data packet generation  
– local buffering of measurement data  
– persistent storage for offline operation  
– sequential resend after reconnect  
– deletion only after confirmed delivery  

Data loss is explicitly avoided by design.

### Communication Layer

– outbound data transmission  
– acknowledgement handling  
– connection health monitoring  
– retry and backoff strategies  

SENSE Core is transport-agnostic.  
Specific protocols are implemented as modules.

### Configuration Management

– structured configuration loading  
– validation of configuration files  
– runtime feature activation or deactivation  
– separation of static and dynamic configuration  

Configuration defines behavior.  
Firmware code remains unchanged.

## What SENSE Core Explicitly Does Not Do

To maintain clarity and stability, SENSE Core explicitly avoids:

– application-specific logic  
– interpretation of sensor semantics  
– user interface definitions  
– visual design decisions  
– domain-specific thresholds  
– business logic  

These concerns belong to Eco applications or SENSE Home.

## Relationship to Eco Applications

Eco applications:
– define meaning  
– define behavior  
– define thresholds and logic  

SENSE Core:
– provides capabilities  
– executes instructions  
– ensures reliability  

Eco applications cannot bypass SENSE Core safety mechanisms.

## Relationship to SENSE Home

SENSE Core:
– operates autonomously  
– remains functional without SENSE Home  
– buffers data during disconnection  

SENSE Home:
– aggregates data  
– performs long-term analysis  
– visualizes system state  
– manages alarms and history  

SENSE Core never depends on SENSE Home availability.

## Extensibility

SENSE Core is designed to be extended through:

– additional sensor modules  
– additional actuator modules  
– additional communication modules  

Extensions must follow the same abstraction rules and must not introduce application logic into the core.

## Summary

SENSE Core is the stable, minimal, and reliable foundation of the SENSE system.

It defines how things work, not what they mean.

All higher-level behavior is defined outside of SENSE Core through configuration and applications.
