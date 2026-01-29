#include <Arduino.h>
#include <Wire.h>

#include "sht3x.h"

#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 4   // GPIO gemss Doku

// DS18B20
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature ds18b20(&oneWire);

void setup() {
  Serial.begin(115200);
  delay(1000);

  // I2C zentral
  Wire.begin();
  delay(200);

  // SHT3x
  if (sht3x_init()) {
    Serial.println("SHT3X OK");
  } else {
    Serial.println("SHT3X INIT FAILED");
  }

  // DS18B20
  ds18b20.begin();
  Serial.println("DS18B20 OK");

  Serial.println("=== SENSOR COMBINED TEST ===");
}

void loop() {
  // --- SHT3x ---
  SHT3xData sht = sht3x_read();
  Serial.print("SHT3X  T=");
  Serial.print(sht.temperature, 2);
  Serial.print(" C  H=");
  Serial.print(sht.humidity, 2);
  Serial.println(" %");

  // --- DS18B20 ---
  ds18b20.requestTemperatures();
  float t_ds = ds18b20.getTempCByIndex(0);

  if (t_ds != DEVICE_DISCONNECTED_C) {
    Serial.print("DS18B20 T=");
    Serial.print(t_ds, 2);
    Serial.println(" C");
  } else {
    Serial.println("DS18B20 READ ERROR");
  }

  Serial.println("---");
  delay(2000);
}
