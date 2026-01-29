# Storage   Marcel Sauder, 2026

## Purpose

This document defines the **RAM-based storage backend** for the SenseModule system.

It specifies how the normative *Storage Record Model* is implemented using volatile memory, without introducing any additional semantics, persistence assumptions, or control logic.

This backend exists to enable early buffering and validation of time-stamped records before non-volatile storage is available.

## Scope

This specification applies exclusively  the RAM storage backend  SenseCore integration of the backend

It explicitly does **not**  record  data  persistence across  overflow recovery  wear leveling or optimisation

## Relationship to Storage Record Model

This backend implements the contract defined  `docs/storage_record_model.md`

No deviation, extension, or reinterpretation of the record model is permitted.

## Backend Characteristics

The RAM backend is defined by the following immutable  volatile  fixed capacity at compile  static memory allocation  deterministic  zero dynamic allocation

## Data Structure

The backend uses a **static ring buffer** of `StorageRecord` entries.

Conceptual structure:

```
StorageRecord buffer[N];
uint16_t write_index;
uint16_t record_count;
```

 `N` is the fixed maximum number of  `write_index` points to the next write  `record_count` tracks the number of valid records

## Write  records are written  the write index advances  when `write_index == N`, behavior is defined by the overflow policy

## Overflow Policy

Default  buffer overflow is **not  `storage_write()` SHALL return `false` when the buffer is  no existing records are overwritten

Optional future behavior (not enabled by  controlled overwrite of oldest  requires explicit configuration and documentation

## Read and Access  the RAM backend does NOT expose any read  records cannot be enumerated or  all stored data is opaque to roles

Any inspection, export, or transfer must be implemented outside this backend.

## Reset  all records are lost on reboot or  no attempt is made to preserve or reconstruct  `record_count` is reset to  `write_index` is reset to zero

This behavior is intentional and required.

## Interface Compliance

The backend MUST implement the following SenseCore storage interface:

```
bool     storage_write(const StorageRecord& record);
uint16_t storage_capacity();
uint16_t storage_count();
```

No additional interface functions are allowed.

## Error  write failures are silent by  no logging is  error counters MAY be maintained internally by SenseCore

## Rationale

The RAM backend exists  validate the storage  enable early system  allow time-stamped buffering without non-volatile  avoid premature architectural commitment

It is not intended for production persistence.

## Stability

This backend is a **reference implementation**.

Its behavior SHALL remain stable unless the underlying storage contract is revised.
memory
testing
contract
to:

required
default
Handling

zero
state
reset
Behavior

inspected
access
Rules

records
default):

full
permitted**
behavior:

monotonically
sequentially
Semantics

position
records
Where:

behavior
only
time
storage
properties:

in:

strategies
reboot
transmission
interpretation
define:

implementation
to:

RAM

Backend 