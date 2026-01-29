#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 4   // gemss Dokumentation GPIO 4

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup() {
  Serial.begin(115200);
  delay(1000);

  sensors.begin();
  Serial.println("DS18B20 TEST START");
}

void loop() {
  sensors.requestTemperatures();
  float t = sensors.getTempCByIndex(0);

  if (t == DEVICE_DISCONNECTED_C) {
    Serial.println("DS18B20 READ ERROR");
  } else {
    Serial.print("DS18B20 TEMP: ");
    Serial.print(t, 2);
    Serial.println(" C");
  }

  delay(2000);
}
