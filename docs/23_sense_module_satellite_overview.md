# SENSE Module Satellite – Overview

© Marcel Sauder, 2026

This document defines the role, scope, and architectural position of the SENSE Module Satellite within the SENSE ecosystem. It clarifies how the Satellite relates to the SENSE Module, SENSE Core, and higher-level applications.

The SENSE Module Satellite is a dedicated, reduced hardware platform designed for distributed sensing tasks.

## Purpose

The SENSE Module Satellite exists to provide reliable, low-cost, distributed data acquisition.

Its primary purpose is to:
– measure a small number of parameters
– attach clear device and sensor identification
– buffer data temporarily if required
– forward data reliably to a SENSE Module

The Satellite is not intended to operate independently or make semantic decisions.

## Position in the SENSE Architecture

Within the SENSE ecosystem, the Satellite occupies a strictly subordinate role.

– SENSE Module (ESP32): aggregation, evaluation, decision-making
– SENSE Module Satellite (ESP8266): sensing and forwarding
– SENSE Home: long-term storage, visualization, system-wide alarms

Satellites never communicate directly with SENSE Home.

## Hardware Platform

The SENSE Module Satellite is typically based on the ESP8266 platform.

Rationale:
– sufficient performance for simple sensing tasks
– integrated WiFi
– low cost
– small form factor
– mature ecosystem

The Satellite hardware is intentionally minimal.

## Firmware and Core Profile

The Satellite runs the same SENSE Core codebase as the SENSE Module.

At boot time, SENSE Core detects the underlying hardware platform.

– ESP8266: SENSE Core enforces satellite core profile
– ESP32: SENSE Core allows full core profile

The satellite core profile disables all functionality not required for sensing and forwarding.

## Capabilities of the Satellite Core Profile

Enabled capabilities:
– device identity and metadata
– sensor reading
– timestamping
– structured data packet generation
– minimal local buffering
– reliable forwarding with acknowledgement
– resend after reconnect

Disabled capabilities:
– Eco application profiles
– local semantic evaluation
– event severity classification
– local display
– actuator control
– direct SENSE Home integration

## Typical Use Cases

Typical Satellite deployments include:
– individual refrigerators in multi-unit installations
– remote or hard-to-access measurement points
– large sensor networks with centralized evaluation
– cost-sensitive monitoring scenarios

Multiple Satellites may forward data to a single SENSE Module.

## Design Philosophy

The SENSE Module Satellite is designed to be:
– simple
– predictable
– replaceable
– inexpensive
– robust

It deliberately avoids feature growth.

## Relationship to Future Hardware

The Satellite is defined as a separate hardware project.

It will have:
– its own hardware repository
– its own hardware README
– its own block diagram and schematics

However, it remains architecturally aligned with the SENSE Module through SENSE Core.

## Summary

The SENSE Module Satellite is a focused sensing node within the SENSE system.

By separating sensing from evaluation and control, the architecture achieves scalability, reliability, and long-term maintainability.

All higher-level logic remains centralized in the SENSE Module and SENSE Home.
