# EcoRoom – Configuration Examples

© Marcel Sauder, 2026

This document provides reference configuration examples for the EcoRoom application profile.

All examples are written in YAML and are intended to demonstrate how EcoRoom behavior is defined purely through configuration, without firmware changes.

## General Configuration Structure

EcoRoom configuration is divided into logical sections:

– device metadata  
– sensors  
– operating mode  
– evaluation logic  
– data forwarding  
– local display  
– storage and offline handling  

Not all sections must be active in every operating mode.

## Common Base Configuration

The following base configuration applies to all EcoRoom operating modes.

```yaml
device:
  name: "sense-room-01"
  location: "office"
  profile: "EcoRoom"

sensors:
  temperature:
    enabled: true
    interval_seconds: 30
  humidity:
    enabled: true
    interval_seconds: 30
  co2:
    enabled: true
    interval_seconds: 60

storage:
  local_buffer:
    enabled: true
    type: "sdcard"
    max_days: 14
