#pragma once

#include <Arduino.h>

enum class SHT3xStatus {
  OK,
  I2C_NOT_RESPONDING,
  WRONG_DATA_LENGTH,
  CRC_ERROR
};

struct SHT3xData {
  float temperature;
  float humidity;
  SHT3xStatus status;
};

bool sht3x_init();
SHT3xData sht3x_read();
const char* sht3x_status_to_string(SHT3xStatus status);
