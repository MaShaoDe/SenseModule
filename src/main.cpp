#include <Arduino.h>
#include <Wire.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <RTClib.h>

// ---------------- CONFIG ----------------
#define ONE_WIRE_BUS 4
#define OLED_ADDR 0x3C
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
// ----------------------------------------

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
RTC_DS3231 rtc;

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup()
{
    Serial.begin(115200);
    delay(500);

    Wire.begin(21, 22);
    Wire.setClock(100000);

    if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
        Serial.println("OLED FAIL");
        while (1);
    }

    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.println("SenseModule");
    display.println("Boot...");
    display.display();

    sensors.begin();

    if (!rtc.begin()) {
        Serial.println("RTC FAIL");
    }

    Serial.println("SYSTEM READY");
}

void loop()
{
    sensors.requestTemperatures();
    float t1 = sensors.getTempCByIndex(0);

    DateTime now = rtc.now();

    char timebuf[16];
    snprintf(timebuf, sizeof(timebuf),
             "%02d:%02d:%02d",
             now.hour(), now.minute(), now.second());

    display.clearDisplay();
    display.setCursor(0, 0);

    display.print("Time: ");
    display.println(timebuf);

    display.print("Temp: ");
    display.print(t1, 1);
    display.println(" C");

    display.display();

    Serial.print("Temp=");
    Serial.print(t1, 1);
    Serial.print(" ");
    Serial.println(timebuf);

    delay(2000);
}
