# SENSE Module

© Marcel Sauder, 2026

The SENSE Module is the primary hardware platform of the SENSE system. It is designed as a robust, modular sensing device capable of running SENSE Core and executing Eco application profiles such as EcoRoom and EcoFridge.

The SENSE Module is not a single-purpose device. It is a configurable platform intended for long-term, extensible environmental monitoring and control systems.

## Purpose

The SENSE Module provides a stable hardware foundation for environmental sensing, offline-capable data acquisition, reliable data forwarding, optional local visualization, and integration into SENSE Home. It serves as the intelligent edge node within the SENSE architecture.

## Architecture Overview

The SENSE Module is based on the ESP32 platform and runs SENSE Core in full core profile.

Key characteristics include sufficient processing and memory resources, concurrent networking and local storage, support for multiple sensors, optional display support, and deterministic offline-first operation.

Application-specific behavior is never hard-coded. All behavior is defined through configuration and Eco application profiles.

## Relationship to Other SENSE Components

### SENSE Core

SENSE Core is the firmware running on the SENSE Module. It provides sensor abstraction, timing and scheduling, storage and buffering, communication and acknowledgement handling, and capability-based feature activation.

The SENSE Module does not embed application logic directly. All higher-level behavior is defined via configuration and Eco profiles.

### Eco Applications

Eco applications define how the SENSE Module behaves in a specific context. Examples include EcoRoom for room monitoring and EcoFridge for refrigerator monitoring and control.

Eco applications run exclusively on SENSE Modules operating in full core profile.

### SENSE Module Satellite

For large-scale or cost-sensitive deployments, the SENSE system also defines a reduced device class called the SENSE Module Satellite.

A SENSE Module Satellite is typically based on ESP8266 hardware and runs SENSE Core in satellite core profile. It performs sensing, buffering, and forwarding only. It does not execute Eco profiles, does not evaluate data semantically, and does not provide a local display.

Satellites forward data to a SENSE Module acting as a master node.

### SENSE Home

SENSE Home is the central software system for aggregation, long-term storage, visualization, and alarm management.

The SENSE Module can operate fully standalone, connected to SENSE Home, or temporarily offline with automatic resynchronization. SENSE Home is optional but recommended for larger or distributed systems.

## Design Principles

The SENSE Module follows these principles: clear separation of hardware, firmware, and application logic; configuration-driven behavior; offline-first reliability; capability-based feature activation; long-term maintainability; and avoidance of unnecessary complexity.

## Intended Use Cases

Typical use cases include room climate monitoring, multi-room sensing systems, refrigerator monitoring, distributed sensor networks, and educational or research environments.

The SENSE Module is not intended for high-power switching, real-time motor control, or safety-critical control systems.

## Repository Structure

```
.
├── README.md
├── docs/
│   ├── 00_nomenclature.md
│   ├── 01_sense_core_overview.md
│   ├── 02_ecoroom_profile.md
│   ├── 03_ecoroom_configuration_example.md
│   └── ...
├── hardware/
│   ├── schematics/
│   ├── pcb/
│   └── bom/
├── firmware/
│   └── sense-core/
└── tools/
```

Documentation in the docs directory defines the conceptual and architectural foundation of the system.

## Project Status

The SENSE Module is under active development. The current focus is on hardware platform definition, ESP32-based design, sensor and storage integration, and preparation for the EcoRoom reference deployment.

## License

This project is licensed under the GNU General Public License v3.0 (GPL-3.0).

See the LICENSE file in the repository root for full license text and conditions.

License information is provided in the repository root.

## Further Reading

See docs/00_nomenclature.md for system terminology and naming conventions. Additional architectural documents are located in the docs directory.

The SENSE Module is the foundation of the SENSE ecosystem. All higher-level behavior is built upon its stability and clarity.
