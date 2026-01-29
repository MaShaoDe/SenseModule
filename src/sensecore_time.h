#pragma once

#include <stdint.h>

// SenseCore time backend types
enum SenseCoreTimeBackend : uint8_t {
    SENSECORE_TIME_BACKEND_MILLIS = 0,
    SENSECORE_TIME_BACKEND_RTC    = 1
};

// Initialize time system (select backend)
void sensecore_time_init(SenseCoreTimeBackend backend);

// Get monotonic time in seconds
uint32_t sensecore_time_now();
