#include <Arduino.h>
#include <Wire.h>
#include "sht3x.h"

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println();
  Serial.println("=== SHT3X ROBUST MODULE TEST ===");

  Wire.begin();

  if (!sht3x_init()) {
    Serial.println("ERROR: SHT3X not detected");
    while (true) {
      delay(1000);
    }
  }

  Serial.println("SHT3X detected");
}

void loop() {
  SHT3xData data = sht3x_read();

  if (data.status == SHT3xStatus::OK) {
    Serial.print("Temperature: ");
    Serial.print(data.temperature, 2);
    Serial.println(" C");

    Serial.print("Humidity: ");
    Serial.print(data.humidity, 2);
    Serial.println(" %RH");
  } else {
    Serial.print("SHT3X ERROR: ");
    Serial.println(sht3x_status_to_string(data.status));
  }

  Serial.println("---");
  delay(5000);
}
