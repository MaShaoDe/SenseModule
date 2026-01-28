#include "display_ssd1306.h"

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define OLED_RESET -1
#define OLED_ADDR 0x3C

static Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
static bool display_ok = false;

bool display_init() {
  if (display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
    display_ok = true;
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.println("SenseModule");
    display.println("Display OK");
    display.display();
    return true;
  }
  return false;
}

static void print2(int v) {
  if (v < 10) display.print("0");
  display.print(v);
}

void display_render(
  int year, int month, int day,
  int hour, int minute, int second,
  float temp1,
  float temp2,
  float humidity
) {
  if (!display_ok) return;

  display.clearDisplay();
  display.setCursor(0, 0);

  // Zeile 1: Zeit + Datum (mit Jahr)
  display.print("Zeit ");
  print2(hour);
  display.print(":");
  print2(minute);

  display.print("  ");
  print2(day);
  display.print(".");
  print2(month);
  display.print(".");
  print2(year % 100);

  // Zeile 2: T1 + Humidity
  display.setCursor(0, 8);
  display.print("T1 ");
  display.print(temp1, 1);
  display.print("C ");

  display.print("H ");
  display.print(humidity, 0);
  display.print("%");

  // Zeile 3: T2
  display.setCursor(0, 16);
  display.print("T2 ");
  display.print(temp2, 1);
  display.print("C");

  display.display();
}
