# ESP32 Decision Guide

## by Marcel Sauder February 2026

This repository provides a practical, engineering-focused overview of common ESP32 variants. The goal is not to repeat datasheets, but to support **real-world decision making** when choosing an ESP32 for PCB design, prototyping, or small-scale production.

For each ESP32 model you will find:
– maximum GPIO count (chip level)
– typical number of physically exposed pins
– realistically usable GPIOs
– approximate pricing (single unit, 2026, CHF)
– concise recommendation notes

All numbers are approximate and intentionally conservative.

## ESP32-WROOM-32

GPIOs:
– Up to 34 GPIOs internally (GPIO 0–39, with restrictions)
– Typical devboards:
– 30-pin version: approx. 25–26 usable GPIOs
– 38-pin version: approx. 30–32 usable GPIOs
– GPIO 34–39 are input-only

Price:
– Module: approx. 3–5 CHF
– Devboard: approx. 5–8 CHF

Recommendation:
The classic ESP32. Extremely mature, well documented, and widely supported. A safe all-round choice for sensors, relays, networking, and mixed I/O projects.

## ESP32-WROVER

GPIOs:
– Up to 34 GPIOs internally
– Typical devboards: 38 pins
– Usable GPIOs: approx. 28–30 (some used by PSRAM)

Price:
– Module: approx. 6–9 CHF
– Devboard: approx. 8–12 CHF

Recommendation:
Similar to WROOM but with integrated PSRAM. Recommended for display-heavy applications, LVGL, graphics buffers, or memory-intensive firmware.

## ESP32 D1 Mini (ESP32-based)

GPIOs:
– Typically 16 physical pins
– Usable GPIOs: approx. 11–13

Price:
– Board: approx. 4–7 CHF

Recommendation:
Very compact and breadboard-friendly. Well suited for modular systems and backplane-style designs. GPIO headroom is limited.

## ESP32-C3

GPIOs:
– Up to 22 GPIOs internally
– Typical devboards: 22–26 pins
– Usable GPIOs: approx. 18–20

Price:
– Module: approx. 2.5–4 CHF
– Devboard: approx. 4–7 CHF

Recommendation:
Modern RISC-V core, low power, BLE support. Excellent for new designs, IoT nodes, sensors, and compact controllers.

## ESP32-C2

GPIOs:
– Up to 14 GPIOs internally
– Typical boards: 14–16 pins
– Usable GPIOs: approx. 10–12

Price:
– Module: approx. 2–3 CHF
– Devboard: approx. 3–5 CHF

Recommendation:
Minimalistic and cost-focused. Suitable only for clearly scoped tasks with very limited I/O requirements.

## ESP32-S2

GPIOs:
– Up to 43 GPIOs internally
– Typical devboards: 38–44 pins
– Usable GPIOs: approx. 36–40

Price:
– Module: approx. 4–6 CHF
– Devboard: approx. 6–9 CHF

Recommendation:
High GPIO count and native USB support. No Bluetooth. Ideal for USB devices, HID, mass storage, or GPIO-intensive designs.

## ESP32-S3

GPIOs:
– Up to 45 GPIOs internally
– Typical devboards: 38–44 pins
– Usable GPIOs: approx. 34–40

Price:
– Module: approx. 5–8 CHF
– Devboard: approx. 7–12 CHF

Recommendation:
One of the most capable ESP32 variants. Native USB, Bluetooth LE, high performance. Best choice for displays, touch interfaces, GUIs, and complex user interfaces.

## ESP32-PICO-D4

GPIOs:
– Up to 34 GPIOs internally
– Physically exposed pins: highly board-dependent, typically 20–28

Price:
– Module: approx. 4–6 CHF
– Board: approx. 6–9 CHF

Recommendation:
System-in-Package solution for space-constrained PCB designs. Well suited for custom boards where footprint matters.

## Quick Selection Summary

– Maximum GPIOs: ESP32-S3 or ESP32-S2
– Proven all-round solution: ESP32-WROOM-32 (38-pin)
– Compact and modern: ESP32-C3
– Minimal and low-cost: ESP32-C2
– Modular and plug-in friendly: ESP32 D1 Mini
– Display and GUI focused: ESP32-S3

This document is intended as a living decision aid for engineers and makers working with the ESP32 ecosystem.
