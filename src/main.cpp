#include <Arduino.h>
#include <Wire.h>

void scan(uint8_t sda, uint8_t scl) {
  Wire.begin(sda, scl);
  delay(100);

  Serial.printf("\nScan SDA=%d SCL=%d\n", sda, scl);
  for (uint8_t addr = 1; addr < 127; addr++) {
    Wire.beginTransmission(addr);
    if (Wire.endTransmission() == 0) {
      Serial.printf("Found device at 0x%02X\n", addr);
    }
  }
  Wire.end();
  delay(500);
}

void setup() {
  Serial.begin(115200);
  delay(1000);

  // Wir testen NUR die realistischen Kandidaten
  scan(21, 22);   // Standard
  scan(22, 21);   // vertauscht
  scan(4, 5);     // häufig bei Breakouts
  scan(16, 17);   // alternative DevKit-Paare
}

void loop() {}

