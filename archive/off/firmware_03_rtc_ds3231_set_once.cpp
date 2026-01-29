#include <Arduino.h>
#include <Wire.h>
#include "rtc_ds3231.h"

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println();
  Serial.println("=== DS3231 SET ONCE ===");

  Wire.begin();

  if (!rtc_init()) {
    Serial.println("ERROR: DS3231 not detected");
    return;
  }

  RTCDateTime setTime;
  setTime.year   = 2026;
  setTime.month  = 1;
  setTime.day    = 28;
  setTime.hour   = 21;
  setTime.minute = 45;
  setTime.second = 0;

  rtc_set(setTime);

  Serial.println("RTC time has been set ONCE.");
}

void loop() {
  delay(1000);
}
