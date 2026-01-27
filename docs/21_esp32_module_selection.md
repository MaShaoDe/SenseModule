# ESP32 Module Selection – SENSE Module v1

© Marcel Sauder, 2026

This document defines the ESP32 module selection for SENSE Module hardware version 1. The goal is to select a module variant that supports SENSE Core in full core profile without unnecessary complexity or premature overdimensioning.

The decision is based on functional requirements, availability, long-term maintainability, and architectural clarity.

## Selection Criteria

The ESP32 module must support:
– stable WiFi operation
– concurrent networking and local storage
– multiple SPI and I²C peripherals
– sufficient RAM for buffering and scheduling
– long-term availability
– mature toolchain support (ESP-IDF, PlatformIO)

Optional but desirable:
– additional RAM headroom
– OTA firmware updates
– broad community adoption

## Considered ESP32 Module Variants

The following ESP32 module families were evaluated:

– ESP32-WROOM-32
– ESP32-WROVER
– ESP32-WROOM-32E / 32UE

Other ESP32 variants (C3, S3, C6) are intentionally excluded at this stage to reduce architectural uncertainty.

## ESP32-WROOM-32

Characteristics:
– integrated Flash memory
– no PSRAM
– widely available
– lowest complexity
– very stable ecosystem

Assessment:
The ESP32-WROOM-32 provides sufficient resources for SENSE Core, EcoRoom, offline buffering, and hybrid operation. It represents the most conservative and robust choice.

## ESP32-WROVER

Characteristics:
– integrated Flash
– additional PSRAM
– higher memory headroom
– slightly higher cost

Assessment:
PSRAM provides additional buffer space and UI flexibility but is not strictly required for SENSE Module v1. Introducing PSRAM increases complexity and potential failure modes.

## ESP32-WROOM-32E / 32UE

Characteristics:
– updated revision of WROOM
– improved RF performance
– optional external antenna support

Assessment:
These variants are functionally equivalent to WROOM-32 for the purposes of SENSE Module v1 and may be used interchangeably depending on availability and enclosure requirements.

## Memory Considerations

SENSE Core relies on:
– structured data packets
– bounded buffering
– deterministic scheduling

The architecture intentionally avoids unbounded memory usage. Therefore, PSRAM is not required for correctness.

If future Eco applications require higher memory bandwidth or graphical interfaces, PSRAM-based modules may be evaluated in later hardware revisions.

## Final Decision

For SENSE Module hardware version 1:

**Selected module:** ESP32-WROOM-32 (or compatible WROOM-32E / 32UE variants)

Rationale:
– sufficient resources for all defined requirements
– lowest architectural risk
– high availability
– simpler power and signal integrity
– easier debugging and long-term maintenance

ESP32-WROVER is explicitly deferred to future revisions if justified by concrete requirements.

## Implications for Hardware Design

– PCB must support the WROOM footprint
– antenna placement must follow Espressif reference designs
– no PSRAM routing required
– Flash size must be verified to meet firmware needs

## Relationship to Other Documents

This decision builds upon:
– docs/20_sense_module_block_diagram.md
– hardware/README.md
– docs/01_sense_core_overview.md

Subsequent documents will define:
– bus and pin strategy
– concrete sensor interfaces
– electrical schematics

## Summary

The ESP32-WROOM family provides the best balance between capability, stability, and simplicity for SENSE Module v1. This choice supports the long-term goals of the SENSE system without introducing unnecessary complexity.
