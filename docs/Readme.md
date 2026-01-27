# docs/

© Marcel Sauder, 2026

This directory contains the **architectural, conceptual, and decision-level documentation** for the SENSE ecosystem.

Documents in this folder describe **what the system is**, **why certain decisions were made**, and **which boundaries apply** to hardware and software implementations.

## Scope of this directory

The docs directory covers:
– system architecture and design philosophy
– naming and nomenclature
– supported and excluded concepts
– power, safety, and reliability principles
– operating modes and profiles
– constraints that guide implementation

These documents intentionally avoid concrete schematics, PCB layouts, or part numbers.

## What does not belong here

The following items are **not** part of this directory:
– KiCad schematics or PCB files
– bills of materials (BOM)
– footprint or component libraries
– implementation-specific wiring details
– board revisions or manufacturing data

Those elements belong in the **hardware/** directory.

## Relationship to hardware/

The documentation in docs/ defines the **rules and intentions**.

The hardware/ directory implements those rules in concrete form.

If a document can be understood without CAD tools or electronics software, it belongs here.

## Naming convention

All documentation files in this directory:
– use lowercase filenames
– use underscores as word separators
– are written in clear, technical English
– describe stable decisions rather than temporary experiments

## Summary

The docs directory serves as the stable foundation of the SENSE ecosystem.

It ensures that all later hardware and software work is guided by explicit, documented decisions rather than assumptions.
