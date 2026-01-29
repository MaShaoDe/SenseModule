#include <Arduino.h>
#include <Wire.h>

#include "sensecore.h"
#include "sc_config.h"

// RTC driver (ONLY place where RTC exists)
#include "../drivers/rtc/rtc_ds3231/rtc_ds3231.h"

// Roles
#include "../roles/base/role_base.h"

static sc_config_t current_config;
static sc_time_t current_time;

void sensecore_init(const sc_config_t& config)
{
    current_config = config;

    Serial.begin(115200);
    Serial.println("SenseCore init");

    Wire.begin();

    // Initialize RTC
    rtc_init();
    Serial.println("SenseCore: RTC init");

    // Initialize time as invalid until first read
    current_time.valid = false;

    if (current_config.role == SC_ROLE_BASE) {
        role_base_init();
    }
}

void sensecore_run_cycle()
{
    static unsigned long last_cycle_ms = 0;
    const unsigned long cycle_interval_ms = 2000;

    unsigned long now_ms = millis();
    if (now_ms - last_cycle_ms < cycle_interval_ms) {
        return;
    }
    last_cycle_ms = now_ms;

    // Read RTC
    RTCDateTime rtc = rtc_now();

    current_time.year   = rtc.year;
    current_time.month  = rtc.month;
    current_time.day    = rtc.day;
    current_time.hour   = rtc.hour;
    current_time.minute = rtc.minute;
    current_time.second = rtc.second;
    current_time.valid  = true;

    // Dispatch role cycle
    if (current_config.role == SC_ROLE_BASE) {
        role_base_cycle();
    }
}

sc_time_t sensecore_now()
{
    return current_time;
}
