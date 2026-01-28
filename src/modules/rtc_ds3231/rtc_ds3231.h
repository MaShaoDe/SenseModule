#ifndef RTC_DS3231_H
#define RTC_DS3231_H

#include <Arduino.h>

struct RTCDateTime {
  uint16_t year;
  uint8_t month;
  uint8_t day;
  uint8_t hour;
  uint8_t minute;
  uint8_t second;
};

bool rtc_init();
RTCDateTime rtc_now();
void rtc_set_now(const RTCDateTime& dt);

#endif
