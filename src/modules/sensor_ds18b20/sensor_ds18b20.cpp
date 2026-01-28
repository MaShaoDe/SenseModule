#include <Arduino.h>

#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 4

static OneWire oneWire(ONE_WIRE_BUS);
static DallasTemperature ds18b20(&oneWire);

bool ds18b20_init() {
  ds18b20.begin();
  return true;
}

float ds18b20_read_c() {
  ds18b20.requestTemperatures();
  return ds18b20.getTempCByIndex(0);
}
