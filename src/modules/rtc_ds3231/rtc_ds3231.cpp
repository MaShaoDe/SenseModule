#include "rtc_ds3231.h"
#include <Wire.h>

#define DS3231_ADDR 0x68

static uint8_t bcd2dec(uint8_t val) {
  return (val >> 4) * 10 + (val & 0x0F);
}

static uint8_t dec2bcd(uint8_t val) {
  return ((val / 10) << 4) | (val % 10);
}

bool rtc_init() {
  Wire.beginTransmission(DS3231_ADDR);
  return (Wire.endTransmission() == 0);
}

RTCDateTime rtc_now() {
  RTCDateTime dt{};

  Wire.beginTransmission(DS3231_ADDR);
  Wire.write(0x00);
  Wire.endTransmission();

  Wire.requestFrom(DS3231_ADDR, 7);

  dt.second = bcd2dec(Wire.read() & 0x7F);
  dt.minute = bcd2dec(Wire.read());
  dt.hour   = bcd2dec(Wire.read());
  Wire.read(); // weekday
  dt.day    = bcd2dec(Wire.read());
  dt.month  = bcd2dec(Wire.read());
  dt.year   = 2000 + bcd2dec(Wire.read());

  return dt;
}

void rtc_set_now(const RTCDateTime& dt) {
  Wire.beginTransmission(DS3231_ADDR);
  Wire.write(0x00);
  Wire.write(dec2bcd(dt.second));
  Wire.write(dec2bcd(dt.minute));
  Wire.write(dec2bcd(dt.hour));
  Wire.write(0x01); // weekday dummy
  Wire.write(dec2bcd(dt.day));
  Wire.write(dec2bcd(dt.month));
  Wire.write(dec2bcd(dt.year - 2000));
  Wire.endTransmission();
}
