# ESP32 Module Selection – SENSE Module v1

© Marcel Sauder, 2026

This document defines the ESP32 module and development board selection for SENSE Module hardware version 1. The goal is to select a platform that fully supports SENSE Core in full core profile while preserving long-term flexibility, clarity, and hardware reserves.

This document supersedes any implicit or informal assumptions regarding ESP32 form factors.

## Purpose

The purpose of this document is to:
– define the ESP32 module family used for SENSE Module v1
– define the ESP32 development board form factor
– document exclusions and non-goals explicitly
– provide a stable reference for schematic and PCB design

## Selection Criteria

The ESP32 platform must support:
– stable WiFi operation
– concurrent networking and local storage
– multiple SPI and I²C peripherals
– sufficient GPIO availability
– sufficient RAM for buffering and scheduling
– long-term availability
– mature toolchain support (ESP-IDF, PlatformIO)

Optional but desirable:
– OTA firmware updates
– broad community adoption
– availability from multiple suppliers

## Evaluated ESP32 Module Families

The following ESP32 module families were evaluated:

– ESP32-WROOM-32
– ESP32-WROVER
– ESP32-WROOM-32E / 32UE

Other ESP32 variants (C3, S3, C6, etc.) are intentionally excluded at this stage to reduce architectural uncertainty and fragmentation.

## ESP32-WROOM-32 Family

Characteristics:
– integrated Flash memory
– no PSRAM
– mature and widely deployed
– stable RF characteristics
– lowest architectural complexity

Assessment:
The ESP32-WROOM-32 family provides sufficient resources for:
– SENSE Core (full core profile)
– EcoRoom
– EcoFridge
– offline buffering using microSD
– hybrid operation with optional display

It represents the most conservative and robust choice for SENSE Module v1.

## ESP32-WROVER Family

Characteristics:
– integrated Flash
– additional PSRAM
– increased memory headroom
– higher cost and complexity

Assessment:
While PSRAM provides additional flexibility, it is not required for correctness or stability of SENSE Module v1. Introducing PSRAM at this stage would increase design complexity without a clearly defined requirement.

The ESP32-WROVER family is therefore deferred to future hardware revisions if justified by concrete use cases.

## Memory Considerations

SENSE Core is designed around:
– bounded memory usage
– structured data packets
– deterministic scheduling

The architecture deliberately avoids unbounded buffering in RAM. Persistent buffering is handled via microSD storage. As a result, additional PSRAM is not required for SENSE Module v1.

## Development Board Form Factor Decision

ESP32 development boards are commonly available in different pin-count variants, most notably 32-pin and 38-pin layouts.

### 38-Pin ESP32 Dev Board

Characteristics:
– increased number of accessible GPIOs
– better separation of SPI, I²C, debug, and status signals
– sufficient reserve pins for future extensions
– reduced need for pin multiplexing

Assessment:
The 38-pin form factor aligns with the defined pin and bus strategy of the SENSE Module. It allows:
– dedicated SPI for microSD
– optional SPI or I²C for display
– clean debug and boot access
– explicit GPIO reservation for future use

### 32-Pin ESP32 Dev Board

Characteristics:
– reduced GPIO availability
– tighter pin constraints
– increased risk of forced multiplexing

Assessment:
The 32-pin form factor does not provide sufficient margin for the SENSE Module architecture without introducing unnecessary constraints or compromises.

### Final Form Factor Decision

**SENSE Module v1 SHALL be based on a 38-pin ESP32 development board.**

The 32-pin ESP32 form factor is explicitly excluded from use in SENSE Module v1.

## Final Decision Summary

For SENSE Module hardware version 1:

– ESP32-WROOM-32 family selected
– WROOM-32E / 32UE variants permitted as drop-in equivalents
– ESP32-WROVER deferred to future revisions
– 38-pin ESP32 dev board form factor mandated
– 32-pin ESP32 dev board form factor excluded

## Implications for Hardware Design

– schematic design must assume 38-pin availability
– PCB layout must accommodate 38-pin footprint
– pin reservation strategy relies on GPIO margin
– antenna placement must follow Espressif reference designs
– flash size must be verified against firmware growth

## Relationship to Other Documents

This decision builds upon:
– docs/20_sense_module_block_diagram.md
– docs/22_sense_module_pin_and_bus_strategy.md
– docs/24_sense_module_schematic_design_guidelines.md
– hardware/README.md

## Summary

The ESP32-WROOM-32 family combined with a 38-pin development board provides the optimal balance of stability, clarity, and extensibility for SENSE Module v1.

This decision deliberately prioritizes architectural margin and long-term maintainability over minimal footprint or short-term convenience.
