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
