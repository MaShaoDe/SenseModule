#include <Arduino.h>

#include "role_base.h"

// SenseCore time
#include "../../sensecore/sensecore.h"

// UI
#include "../../ui/display_ssd1306/display_ssd1306.h"

// Sensor drivers
#include "../../drivers/sensors/sensor_sht3x/sht3x.h"
#include "../../drivers/sensors/sensor_ds18b20/sensor_ds18b20.h"

static bool display_ok = false;
static bool sht3x_ok = false;
static bool ds18b20_ok = false;

void role_base_init()
{
    display_ok = display_init();
    Serial.println(display_ok ? "Base role: display init OK"
                              : "Base role: display NOT found");

    sht3x_ok = sht3x_init();
    Serial.println(sht3x_ok ? "Base role: SHT3x OK"
                            : "Base role: SHT3x FAIL");

    ds18b20_init();
    ds18b20_ok = true;
    Serial.println("Base role: DS18B20 init");
}

void role_base_cycle()
{
    if (!display_ok) {
        return;
    }

    sc_time_t now = sensecore_now();

    // Fallback time if RTC not valid
    int year   = now.valid ? now.year   : 2026;
    int month  = now.valid ? now.month  : 1;
    int day    = now.valid ? now.day    : 1;
    int hour   = now.valid ? now.hour   : 0;
    int minute = now.valid ? now.minute : 0;
    int second = now.valid ? now.second : 0;

    float temp_sht = 0.0f;
    float hum_sht  = 0.0f;
    float temp_ds  = 0.0f;

    if (sht3x_ok) {
        SHT3xData sht = sht3x_read();
        temp_sht = sht.temperature;
        hum_sht  = sht.humidity;
    }

    if (ds18b20_ok) {
        temp_ds = ds18b20_read_c();
    }

    display_render(
        year, month, day,
        hour, minute, second,
        temp_sht,
        temp_ds,
        hum_sht
    );
}
