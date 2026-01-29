#include <Arduino.h>

// Anzeige
extern void display_init();
extern void display_update();

// SIMULIERTE Messwerte (naechster Schritt: echte Daten)
float sense_temperature = 23.4;
float sense_humidity    = 56.7;

void setup() {
  Serial.begin(115200);
  delay(500);
  display_init();
}

void loop() {
  // Dummy-Aenderung, um Bewegung zu sehen
  sense_temperature += 0.1;
  if (sense_temperature > 25.0) sense_temperature = 23.0;

  display_update();
  delay(1000);
}
