# Firmware Build Environment v1 – Sense-Module Core

© Marcel Sauder · Sense Module · January 2026

This document describes the recommended firmware build environment for the Sense-Module Core v1. It is intended primarily for contributors and collaborators, ensuring a reproducible and well-understood development setup.

The project standard is **PlatformIO**.

## Rationale

PlatformIO was chosen because it:

* provides a consistent cross-platform toolchain
* integrates dependency management
* supports ESP32 reliably
* scales well for collaborative and long-term projects

This document is informational. Contributors are expected to adapt it to their local setup where required.

## Supported Host Systems

* macOS (primary reference)
* Linux (secondary)
* Windows (not documented)

## Required Tools

* PlatformIO Core or PlatformIO IDE
* Python (managed internally by PlatformIO)
* Git

## Project Structure

```
SenseModule/
├── platformio.ini
├── src/
│   └── main.cpp
├── include/
├── lib/
├── test/
└── docs/
```

## platformio.ini (Reference)

```
[env:esp32dev]
platform = espressif32
board = esp32dev
framework = arduino
monitor_speed = 115200
upload_speed = 921600

build_flags =
    -D SENSE_MODULE_CORE
```

## Build and Upload Workflow

* `pio run` – build firmware
* `pio run -t upload` – upload to ESP32
* `pio device monitor` – open serial monitor

## Serial Monitor

* Baud rate: 115200
* Used for bring-up diagnostics and status output

## Dependency Management

* All external libraries must be declared via PlatformIO
* No manual library copying into the project tree
* Version pinning recommended for stability

## Coding Conventions

* C++ (Arduino framework)
* One hardware responsibility per module
* No dynamic allocation in core
* Explicit initialization order

## Contribution Notes

* All contributions must build using PlatformIO
* Hardware-Scope v1 pin assignment is authoritative
* New hardware support must not break v1 compatibility

This build environment definition ensures that Sense-Module Core development remains consistent, maintainable, and contributor-friendly.
