#include <Arduino.h>
#include "sensecore_time.h"

// current backend (default: millis)
static SenseCoreTimeBackend current_backend = SENSECORE_TIME_BACKEND_MILLIS;

void sensecore_time_init(SenseCoreTimeBackend backend)
{
    current_backend = backend;
}

uint32_t sensecore_time_now()
{
    switch (current_backend) {

        case SENSECORE_TIME_BACKEND_RTC:
            // placeholder for future RTC implementation
            // must return seconds, monotonic
            return millis() / 1000;

        case SENSECORE_TIME_BACKEND_MILLIS:
        default:
            return millis() / 1000;
    }
}
