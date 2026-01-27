# Bring-up Test Checklist v1 – Hardware-Scope

© Marcel Sauder · Sense Module · January 2026

This document defines the step-by-step bring-up and verification checklist for the Hardware-Scope v1 test environment. The goal is to validate power, communication buses, peripherals, and basic firmware functionality in a controlled and reproducible manner.

The checklist is intended to be followed sequentially.

## 1. Visual Inspection

* Verify correct orientation of ESP32 DevKitC V3
* Check all jumper wires for correct placement
* Confirm common GND connection across all modules
* Verify no obvious shorts on power rails

## 2. Power Supply Verification

* Set breadboard power supply input (USB-C or lab PSU)
* Verify output voltages with multimeter:

  * 5 V rail within tolerance
  * 3.3 V rail within tolerance
* Confirm ESP32 power LED is on

## 3. ESP32 Boot Test

* Connect ESP32 via USB to host computer
* Open serial monitor
* Reset ESP32
* Verify clean boot messages in serial output
* Confirm no continuous reboot or brownout messages

## 4. I²C Bus Scan

* Upload minimal I²C scanner firmware
* Scan I²C bus on GPIO 21 (SDA) and GPIO 22 (SCL)
* Verify presence of:

  * DS3231M RTC
  * SHT31 or GY-SHT30-D sensor
  * OLED SSD1306 display
* If devices are missing:

  * Enable I²C pull-ups via jumper
  * Re-check wiring

## 5. OLED Display Test

* Upload minimal SSD1306 test firmware
* Verify display initialization
* Render test text or pattern
* Confirm correct orientation and readability

## 6. RTC Test

* Read current time from DS3231M
* Set RTC time if required
* Power-cycle main supply
* Verify RTC keeps time using backup battery

## 7. Sensor Test

### SHT31 / GY-SHT30-D

* Read temperature and humidity values
* Verify values are plausible
* Confirm no I²C communication errors

### DS18B20

* Detect sensor on 1-Wire bus (GPIO 4)
* Read temperature value
* Verify stable readings

## 8. microSD Card Test

* Insert formatted microSD card
* Initialize SPI bus
* Mount filesystem
* Create test file
* Write sample data
* Read back and verify contents

## 9. Status LED Test

* Toggle green LED via GPIO 16
* Toggle red LED via GPIO 17
* Verify correct brightness and polarity

## 10. Button Test

* Press reset button

* Verify ESP32 resets cleanly

* Press user button (GPIO 27)

* Verify button press is detected in firmware

## 11. Configuration Jumper Test

* Toggle jumper state
* Verify firmware detects configuration change
* Confirm no undefined states occur

## 12. Stability Test

* Run system for extended period
* Monitor serial output for errors
* Verify no spontaneous resets
* Confirm stable sensor readings over time

## Completion Criteria

The bring-up is considered successful when all steps above pass without errors and the system operates stably under continuous operation.

This checklist serves as the reference procedure for validating all Hardware-Scope v1 builds.
