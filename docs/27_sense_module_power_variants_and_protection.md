# SENSE Module – Power Variants and Protection

© Marcel Sauder, 2026

This document defines the supported power supply variants for the SENSE Module and specifies mandatory protection, filtering, and stabilisation measures. It complements the general power philosophy described in Docs/26 and translates it into concrete, enforceable constraints.

The focus is on electrical robustness, protection against real-world disturbances, and long-term hardware reliability.

## Purpose

The purpose of this document is to:
– define which power supply variants are permitted
– clearly exclude unsupported approaches
– mandate protection and filtering requirements
– ensure consistent behaviour across installations
– prevent later reintroduction of unstable power concepts

## Supported Power Variants

Exactly two power supply variants are supported for the SENSE Module.

### Variant A – External DC 12 V Supply

This is the primary and reference power variant.

Characteristics:
– external, certified DC power supply
– nominal output voltage: 12 V DC
– sufficient current reserve for WiFi peak loads
– suitable for continuous 24/7 operation
– compatible with fixed installations

The external supply must be considered electrically imperfect and is treated as a potentially noisy source.

### Variant B – Direct AC 110–220 V Supply (via Power Board)

This variant is implemented exclusively through a separate power board.

Characteristics:
– input range: 110–220 V AC
– automatic voltage detection or clearly defined regional variants
– use of certified AC/DC modules only
– certifications such as TÜV, SEV, CE, UL strongly preferred
– strict separation between primary and secondary domains

Under no circumstances is mains voltage routed onto the SENSE Module logic board.

## Explicitly Excluded Variants

The following power approaches are explicitly excluded:

– 5 V supplies
– USB-powered adapters
– USB-C power delivery
– unregulated or poorly regulated wall adapters
– direct battery-only operation

These approaches are excluded due to instability, poor transient behaviour, and increased hardware risk.

## Separation of Power and Logic

All power handling beyond basic regulation must occur outside the logic board.

– power input conditioning and protection occur before the logic board
– logic board input is always conditioned 12 V DC
– power boards and logic boards are electrically and physically separated

This separation is mandatory and non-negotiable.

## Mandatory Input Protection

Every power input must include protection and conditioning elements appropriate to its variant.

Typical mandatory elements include:
– input fuse or resettable protection element
– reverse polarity protection (DC variant)
– transient voltage suppression (TVS or equivalent)
– surge and spike protection
– bulk capacitance for energy buffering
– RC or LC filtering for noise suppression

Exact component selection is implementation-specific but omission of these functions is not permitted.

## Filtering and Stabilisation

The power input stage must address:
– conducted noise
– voltage spikes and transients
– short brownouts
– load-induced disturbances

Filtering and stabilisation must be dimensioned for worst-case operating conditions, not nominal values.

## Downstream Regulation

After input conditioning:
– 12 V is supplied to the SENSE Module logic board
– further regulation to 5 V and 3.3 V occurs locally on the logic board

This ensures identical electrical conditions for the logic board across all power variants.

## Safety and Certification Considerations

For AC-powered variants:
– only certified AC/DC modules are permitted
– creepage and clearance requirements must be respected
– protective earth handling must follow module specifications
– mechanical separation must be clearly visible in layout

Certification requirements are treated as design constraints, not afterthoughts.

## Relationship to Other Documents

This document builds upon:
– docs/26_sense_module_power_design_overview.md
– docs/24_sense_module_schematic_design_guidelines.md
– docs/25_sense_module_schematics_overview.md

Future documents may extend this with:
– buffered power options
– battery-backed supply variants
– region-specific installation guidelines

## Summary

The SENSE Module power architecture deliberately restricts the number of supported variants.

By enforcing DC 12 V as the logic input, excluding unreliable supply methods, mandating robust protection, and separating power handling from logic, the system achieves predictable behaviour and long-term resilience in real-world environments.
