#include <Arduino.h>
#include <Wire.h>

#include "sht3x.h"
#include "rtc_ds3231.h"

void setup() {
    Serial.begin(115200);
    delay(1000);

    Serial.println();
    Serial.println("=== SenseModule MAIN START ===");

    Wire.begin();

    if (!sht3x_init()) {
        Serial.println("ERROR: SHT3X not detected");
    } else {
        Serial.println("SHT3X OK");
    }

    if (!rtc_init()) {
        Serial.println("ERROR: DS3231 not detected");
    } else {
        Serial.println("DS3231 OK");
    }
}

void loop() {
    SHT3xData sht = sht3x_read();
    RTCDateTime now = rtc_now();

    Serial.printf(
        "%04d-%02d-%02d %02d:%02d:%02d | %.2f C | %.2f %%RH\n",
        now.year, now.month, now.day,
        now.hour, now.minute, now.second,
        sht.temperature,
        sht.humidity
    );

    delay(5000);
}
