#include <Arduino.h>

unsigned long counter = 0;
unsigned long lastMillis = 0;

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println();
  Serial.println("=== ESP32 BOOT OK ===");
  Serial.println("Firmware: firmware_00_esp32_lifesign");
  Serial.println("Status: running");
  Serial.println("====================");
}

void loop() {
  unsigned long now = millis();

  if (now - lastMillis >= 1000) {
    lastMillis = now;
    counter++;

    Serial.print("Uptime ");
    Serial.print(counter);
    Serial.println(" s");
  }
}
#include <Arduino.h>
#include <Wire.h>

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println();
  Serial.println("=== I2C SCAN START ===");

  Wire.begin();   // nutzt die Standard-I2C-Pins des ESP32

  byte count = 0;

  for (byte address = 1; address < 127; address++) {
    Wire.beginTransmission(address);
    byte error = Wire.endTransmission();

    if (error == 0) {
      Serial.print("I2C device found at 0x");
      if (address < 16) Serial.print("0");
      Serial.print(address, HEX);
      Serial.println();
      count++;
    }
  }

  if (count == 0) {
    Serial.println("No I2C devices found");
  } else {
    Serial.print("Total devices found: ");
    Serial.println(count);
  }

  Serial.println("=== I2C SCAN DONE ===");
}

void loop() {
  delay(5000);
}
