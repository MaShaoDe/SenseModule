#include <Arduino.h>
#include <Wire.h>

#include "sht3x.h"
#include "rtc_ds3231.h"

#include <OneWire.h>
#include <DallasTemperature.h>

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define ONE_WIRE_BUS 4

// ---------- Display ----------
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define OLED_RESET -1
#define OLED_ADDR 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// ---------- DS18B20 ----------
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature ds18b20(&oneWire);

bool display_ok = false;

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
  }

  // DS18B20
  ds18b20.begin();
  Serial.println("DS18B20 OK");

  // Display (optional!)
  if (display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
    display_ok = true;
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.println("SenseModule");
    display.println("Display OK");
    display.display();
    Serial.println("DISPLAY OK");
  } else {
    Serial.println("DISPLAY NOT FOUND");
  }

  Serial.println("=== CORE + DISPLAY TEST ===");
}

void loop() {
  RTCDateTime now = rtc_now();
  SHT3xData sht = sht3x_read();

  ds18b20.requestTemperatures();
  float t_ds = ds18b20.getTempCByIndex(0);

  // Serial
  Serial.print("TIME ");
  Serial.print(now.hour); Serial.print(":");
  Serial.print(now.minute); Serial.print(":");
  Serial.println(now.second);

  Serial.print("SHT3X ");
  Serial.print(sht.temperature, 1);
  Serial.print("C ");
  Serial.print(sht.humidity, 1);
  Serial.println("%");

  Serial.print("DS18B20 ");
  Serial.print(t_ds, 1);
  Serial.println("C");

  // Display (nur Anzeige)
  if (display_ok) {
    display.clearDisplay();
    display.setCursor(0, 0);

    display.print(now.hour);
    display.print(":");
    display.print(now.minute);
    display.println();

    display.print("T ");
    display.print(sht.temperature, 1);
    display.print("C ");

    display.print(t_ds, 1);
    display.println("C");

    display.print("H ");
    display.print(sht.humidity, 0);
    display.println("%");

    display.display();
  }

  Serial.println("---");
  delay(2000);
}
