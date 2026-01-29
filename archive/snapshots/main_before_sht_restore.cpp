#include <Arduino.h>
#include <Wire.h>
#include "rtc_ds3231.h"
#include "sht3x.h"

void setup() {
  Serial.begin(115200);
  delay(1000);

  // I2C zentral initialisieren
  Wire.begin();
  delay(500);

  // RTC nur lesen, nicht setzen
  rtc_init();
  delay(200);

  // Sensor initialisieren
  if (!sht3x_init()) {
    Serial.println("SHT3X INIT FAILED");
  } else {
    Serial.println("SHT3X OK");
  }
}

void loop() {
  float temperature = 0.0;
  float humidity = 0.0;

  bool ok = sht3x_read(&temperature, &humidity);

  if (ok) {
    Serial.print("TEMP=");
    Serial.print(temperature, 2);
    Serial.print(" C  HUM=");
    Serial.print(humidity, 2);
    Serial.println(" %");
  } else {
    Serial.println("SHT3X READ ERROR");
  }

  delay(2000);
}
