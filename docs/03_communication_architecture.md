# SENSE Communication Architecture

© Marcel Sauder, 2026

This document defines the communication architecture of the SENSE ecosystem. It describes how SENSE Modules transmit data, how different transport technologies are integrated, and which architectural boundaries apply.

The goal is a **clean, modular, and transport-agnostic system** that supports both low-power outdoor nodes and fully featured indoor devices without fragmenting firmware or system design.

## Core Principle

Communication technology is **not a device type** and **not an application concern**.

All communication mechanisms are implemented as **transport modules** beneath SENSE Core.

SENSE Core:
– produces structured data packets
– buffers data reliably
– hands packets to a transport interface
– expects acknowledgements

The Core does not depend on any specific transmission technology.

## Transport-Agnostic Design

SENSE Core treats all communication channels equally.

Whether data is transmitted via WiFi, LoRa, or future transports is irrelevant to:
– sensor acquisition
– storage logic
– retry handling
– operating modes
– Eco application behavior

Transport modules implement a common interface and can be exchanged without modifying core logic.

## Supported Communication Technologies

### WiFi Transport

WiFi is the default transport for indoor and powered deployments.

Characteristics:
– higher bandwidth
– higher power consumption
– continuous or semi-continuous connectivity
– direct integration with SENSE Home

Typical use cases:
– room monitoring
– refrigerator monitoring and control
– wall-mounted displays
– systems with permanent power supply

WiFi is well suited for:
– frequent transmissions
– interactive systems
– local networks

### LoRa Transport

LoRa is a low-power, long-range transport intended for distributed and off-grid deployments.

Characteristics:
– very low energy consumption
– long transmission range
– short transmission windows
– small payload sizes
– intermittent connectivity

Typical use cases:
– outdoor temperature satellites
– solar-powered sensor nodes
– remote measurement points
– large-area sensing deployments

LoRa is especially suited for:
– infrequent measurements
– battery or solar operation
– deep sleep based systems

## Communication Modules

Communication technology is implemented via **communication modules**.

A communication module:
– handles physical transmission
– implements retry and acknowledgement mapping
– reports link availability
– exposes a unified send interface to SENSE Core

Examples:
– WiFi communication module
– LoRa communication module

Multiple communication modules may exist, but only one is active at a time per device.

## Relationship to Operating Modes

Operating modes are **independent of communication technology**.

The same operating modes apply regardless of transport:
– capture_only
– forward_only
– store_and_forward
– local_evaluate
– hybrid

For example:
– an outdoor LoRa node typically runs in forward_only
– an indoor WiFi node may run in hybrid

The transport layer does not alter operating mode semantics.

## Relationship to Hardware Variants

Communication technology does not define a hardware class.

A SENSE Module:
– may include WiFi
– may include LoRa
– may support both

Hardware variants differ only by:
– populated communication hardware
– antenna configuration
– power design constraints

All variants:
– run the same SENSE Core
– support the same operating modes
– share the same configuration model

## Energy Considerations

Transport choice strongly influences energy behavior.

General guidance:
– WiFi is recommended for powered, indoor systems
– LoRa is recommended for low-power, outdoor, or solar-powered systems

Energy management remains a responsibility of SENSE Core and hardware design, not the transport logic itself.

## Extensibility

The communication architecture is designed to support future transports, such as:
– wired Ethernet
– RS485 or fieldbus systems
– point-to-point radio links

New transports must:
– implement the standard communication module interface
– not introduce application logic
– not bypass SENSE Core buffering and acknowledgement handling

## Summary

The SENSE communication architecture ensures:
– transport independence
– unified firmware
– scalable deployment models
– clean separation of concerns

Communication technology is a replaceable layer, not a system-defining choice.

This approach enables SENSE Modules to operate reliably across indoor, outdoor, powered, and off-grid environments without architectural fragmentation.
