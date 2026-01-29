#include "sht3x.h"
#include <Wire.h>

#define SHT3X_ADDR 0x44

// CRC8 nach Sensirion (Polynomial 0x31)
static uint8_t sht3x_crc8(const uint8_t* data, uint8_t len) {
  uint8_t crc = 0xFF;
  for (uint8_t i = 0; i < len; i++) {
    crc ^= data[i];
    for (uint8_t b = 0; b < 8; b++) {
      crc = (crc & 0x80) ? (crc << 1) ^ 0x31 : (crc << 1);
    }
  }
  return crc;
}

bool sht3x_init() {
  Wire.beginTransmission(SHT3X_ADDR);
  return (Wire.endTransmission() == 0);
}

SHT3xData sht3x_read() {
  SHT3xData data;
  data.status = SHT3xStatus::I2C_NOT_RESPONDING;

  // Start measurement: High repeatability, no clock stretching
  Wire.beginTransmission(SHT3X_ADDR);
  Wire.write(0x24);
  Wire.write(0x00);
  if (Wire.endTransmission() != 0) {
    return data;
  }

  delay(20);

  Wire.requestFrom((uint8_t)SHT3X_ADDR, (uint8_t)6);
  if (Wire.available() != 6) {
    data.status = SHT3xStatus::WRONG_DATA_LENGTH;
    return data;
  }

  uint8_t raw[6];
  for (int i = 0; i < 6; i++) {
    raw[i] = Wire.read();
  }

  if (sht3x_crc8(raw, 2) != raw[2] ||
      sht3x_crc8(raw + 3, 2) != raw[5]) {
    data.status = SHT3xStatus::CRC_ERROR;
    return data;
  }

  uint16_t rawTemp = (raw[0] << 8) | raw[1];
  uint16_t rawHum  = (raw[3] << 8) | raw[4];

  data.temperature = -45.0 + 175.0 * ((float)rawTemp / 65535.0);
  data.humidity    = 100.0 * ((float)rawHum  / 65535.0);
  data.status = SHT3xStatus::OK;

  return data;
}

const char* sht3x_status_to_string(SHT3xStatus status) {
  switch (status) {
    case SHT3xStatus::OK:                return "OK";
    case SHT3xStatus::I2C_NOT_RESPONDING:return "I2C not responding";
    case SHT3xStatus::WRONG_DATA_LENGTH:return "Wrong data length";
    case SHT3xStatus::CRC_ERROR:        return "CRC error";
    default:                            return "Unknown";
  }
}
