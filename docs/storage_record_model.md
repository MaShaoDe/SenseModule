# Storage Record  Marcel Sauder, 2026

## Purpose

This document defines the **normative storage and record model** for the SenseModule ecosystem.

It specifies **what a measurement record is**, **how it may be written**, and **which boundaries apply** to storage handling.

This document intentionally avoids any reference to concrete storage media, databases, filesystems, or transport mechanisms.

It is binding for all SenseCore implementations and all current and future storage backends.

## Scope

This specification applies   all Sense roles writing measurement  all storage backends (RAM, Flash, FRAM, future implementations)

It does **not** apply  data  persistence  aggregation or  visualization or  SenseHome or external systems

## Core Principles

The storage system follows these immutable  storage is a **SenseCore  roles may **only write**, never manage or interpret  records are **append-only** and immutable after  timestamps are provided **exclusively by  storage backends are ** no backend-specific behavior is visible to roles

## Terminology

### Record

A **Record** is an atomic, time-stamped measurement entry.

Once written, a record SHALL NOT be modified, deleted, or reinterpreted.

### Storage Backend

A **Storage Backend** is a concrete implementation responsible for physically storing records.

Backends may differ in capacity and persistence, but MUST adhere to the same logical contract.

### Storage Interface

The **Storage Interface** is the only API exposed by SenseCore for record storage.

No role may access a backend directly.

## Record Definition

A record is defined as the following fixed structure:

```
struct StorageRecord {
    uint32_t timestamp;
    uint16_t source_id;
    uint16_t type_id;
    int32_t  value;
    uint8_t  flags;
};
```

### Field Semantics

** time provided by  unit and epoch are defined globally by  roles MUST NOT generate or modify timestamps

**source_ unique identifier of the writing role or  numeric  no semantic meaning inside storage

**type_ identifies the measurement type or  interpretation is explicitly outside storage scope

** normalized numeric measurement  scaling is defined by the writing  storage treats the value as opaque

** reserved for future  MUST be set to zero unless explicitly specified later

## Writing  a role MAY write at most **one record per execution  writing is **non- failed writes MUST NOT stall system  storage write failures are silent by  error counters MAY be implemented inside SenseCore

## Storage Interface Contract

SenseCore SHALL expose the following minimal interface:

```
bool     storage_write(const StorageRecord& record);
uint16_t storage_capacity();
uint16_t storage_count();
```

No additional read, delete, iterate, or query functions are permitted at this level.

## Explicit Non-Goals

The storage system explicitly does NOT  record retrieval or  deletion or cleanup  aggregation or statistical  wear leveling or lifetime  persistence guarantees across  data integrity  filesystem semantics

## Future Compatibility

This record model is intentionally designed to map directly  static RAM ring  SPI NOR   sequential export streams

No changes to this specification are required when introducing new storage backends.

## Stability

This document defines a **stable contract**.

Any change to this specification requires an explicit architectural decision and versioned update.
FRAM
Flash
buffers
onto:

verification
reboots
optimization
functions
mechanisms
querying
provide:

default
execution
blocking**
cycle**
Rules

use
flags**
role
value
value**
channel
id**
only
sensor
id**
SenseCore
SenseCore
timestamp**
interchangeable**
SenseCore**
writing
storage
capability**
principles:

UI
analysis
guarantees
transmission
to:

data
SenseCore
to:

Model

