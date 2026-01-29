#include <Arduino.h>
#include "rtc_ds3231.h"

static RTCDateTime datetime_from_compile_time() {
  RTCDateTime dt;

  const char* date = __DATE__;  // z.B. "Jan 28 2026"
  const char* time = __TIME__;  // z.B. "22:18:03"

  char monthStr[4];
  int year, day;
  sscanf(date, "%3s %d %d", monthStr, &day, &year);

  static const char* months = "JanFebMarAprMayJunJulAugSepOctNovDec";
  dt.month = (strstr(months, monthStr) - months) / 3 + 1;

  dt.year = year;
  dt.day  = day;

  sscanf(time, "%d:%d:%d", &dt.hour, &dt.minute, &dt.second);

  return dt;
}

void setup() {
  Serial.begin(115200);
  delay(1000);

  rtc_init();
  rtc_set_now(datetime_from_compile_time());

  Serial.println("RTC SET ONCE DONE");
}

void loop() {
  delay(1000);
}
