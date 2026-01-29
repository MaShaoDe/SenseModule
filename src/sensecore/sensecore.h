#pragma once

#include "sc_config.h"

// SenseCore time representation (RTC-agnostic)
typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
    bool valid;
} sc_time_t;

// SenseCore lifecycle
void sensecore_init(const sc_config_t& config);
void sensecore_run_cycle();

// Time access (read-only for roles)
sc_time_t sensecore_now();
