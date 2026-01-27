# EcoRoom – Room Monitoring Application Profile

© Marcel Sauder, 2026

This document defines EcoRoom, the first reference application profile for the SENSE system.

EcoRoom is a non-invasive room monitoring profile focused on environmental sensing, data reliability, and flexible deployment modes. It serves as the conceptual and technical foundation for all subsequent Eco applications.

## Purpose of EcoRoom

EcoRoom provides structured monitoring of indoor environmental conditions.

Its primary goals are:
– reliable measurement  
– temporal stability  
– offline resilience  
– flexible system integration  

EcoRoom deliberately avoids actuator control in its initial stage.

## Measured Parameters

EcoRoom monitors the following parameters:

– air temperature  
– relative humidity  
– CO₂ concentration  

Additional parameters may be added in later stages without changing the fundamental profile structure.

## Core Characteristics

EcoRoom is designed as:

– read-only (no control actions)  
– configuration-driven  
– usable in standalone and networked scenarios  
– tolerant to network failures  
– suitable as a reference implementation  

## Operating Modes

EcoRoom defines three operating modes.  
Operating modes are configuration states and do not change firmware code.

### Operating Mode 1: Local Evaluate

The SENSE Module evaluates data locally.

Capabilities:
– local threshold evaluation  
– trend and time-series analysis  
– event generation  
– optional local alarms  
– optional forwarding to SENSE Home  

This mode allows autonomous operation without external systems.

### Operating Mode 2: Forward Only

The SENSE Module acts as a pure sensing node.

Capabilities:
– data acquisition only  
– no local semantic evaluation  
– transmission of structured measurement data to SENSE Home  
– verification of successful delivery  
– local storage during connection loss  
– automatic resend after reconnection  

This mode is optimized for large, centrally evaluated systems.

### Operating Mode 3: Hybrid Local Display + Forward

The SENSE Module provides local insight while remaining system-integrated.

Capabilities:
– local evaluation  
– local visualization if a display is present  
– trend and value presentation  
– parallel forwarding to SENSE Home  
– identical offline and resend behavior as Forward Only  

This mode is intended for spaces with direct human interaction.

## Offline and Synchronization Strategy

EcoRoom relies on SENSE Core for data reliability.

Behavior:
– measurement data is packaged into structured data packets  
– packets are transmitted to SENSE Home  
– delivery is confirmed via acknowledgement  
– unconfirmed packets are stored locally  
– stored packets are resent sequentially after reconnection  
– packets are deleted only after confirmed delivery  

Data integrity is prioritized over real-time availability.

## Configuration Philosophy

EcoRoom behavior is fully defined via configuration.

Typical configuration aspects include:
– enabled sensors  
– sampling intervals  
– operating mode selection  
– threshold definitions  
– display enablement  
– forwarding targets  

Changing behavior never requires firmware changes.

## Relationship to SENSE Core

EcoRoom:
– defines meaning and interpretation  
– defines thresholds and logic  
– defines presentation behavior  

SENSE Core:
– provides sensing, timing, storage, and communication  
– enforces safety and reliability  
– executes configuration-defined behavior  

EcoRoom cannot bypass SENSE Core mechanisms.

## Relationship to SENSE Home

EcoRoom may operate:
– fully standalone  
– partially connected  
– fully integrated into SENSE Home  

SENSE Home is optional but recommended for:
– long-term storage  
– cross-room analysis  
– visualization  
– alarm aggregation  

EcoRoom remains functional without SENSE Home.

## Role as Reference Profile

EcoRoom is the first reference profile and serves as:

– a validation of SENSE Core architecture  
– a blueprint for further Eco applications  
– a testing ground for operating modes  
– a documentation anchor  

Subsequent profiles such as EcoFridge build directly on EcoRoom concepts.

## Summary

EcoRoom is a minimal, robust, and extensible room monitoring application.

It defines how environmental sensing is structured within the SENSE system while remaining independent of specific deployment scenarios.
