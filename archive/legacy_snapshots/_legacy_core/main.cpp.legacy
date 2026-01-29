#include <Arduino.h>
#include <Wire.h>

#include "../modules/rtc_ds3231/rtc_ds3231.h"
#include "../modules/sensor_sht3x/sht3x.h"
#include "../modules/sensor_ds18b20/sensor_ds18b20.h"
#include "../modules/display_ssd1306/display_ssd1306.h"

void setup() {
  Serial.begin(115200);
  delay(1000);

  Wire.begin();
  delay(200);

  // RTC
  rtc_init();
  Serial.println("RTC OK");

  // SHT3x
  if (sht3x_init()) {
    Serial.println("SHT3X OK");
  } else {
    Serial.println("SHT3X FAIL");
  }

  // DS18B20
  ds18b20_init();
  Serial.println("DS18B20 OK");

  // Display
  if (display_init()) {
    Serial.println("DISPLAY OK");
  } else {
    Serial.println("DISPLAY NOT FOUND");
  }

  Serial.println("=== CORE STARTED ===");
}

void loop() {
  static unsigned long last_cycle = 0;
  const unsigned long cycle_ms = 2000;

  if (millis() - last_cycle < cycle_ms) {
    return;
  }
  last_cycle = millis();

  // Zeit lesen
  RTCDateTime now = rtc_now();

  // Sensoren lesen
  SHT3xData sht = sht3x_read();
  float temp_ds = ds18b20_read_c();

  // Serielle Ausgabe
  Serial.print("TIME ");
  Serial.print(now.hour);
  Serial.print(":");
  Serial.print(now.minute);
  Serial.print(":");
  Serial.println(now.second);

  Serial.print("TEMP1 SHT3X ");
  Serial.print(sht.temperature, 1);
  Serial.println(" C");

  Serial.print("TEMP2 DS18B20 ");
  Serial.print(temp_ds, 1);
  Serial.println(" C");

  Serial.print("HUMIDITY ");
  Serial.print(sht.humidity, 0);
  Serial.println(" %");

  Serial.println("---");

  // Display (nur Darstellung)
  display_render(
    now.year, now.month, now.day,
    now.hour, now.minute, now.second,
    sht.temperature,
    temp_ds,
    sht.humidity
  );
}
