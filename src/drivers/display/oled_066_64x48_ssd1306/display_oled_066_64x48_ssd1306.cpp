/*
 *  display_oled_066_64x48_ssd1306.cpp
 *
 *  OLED Display Driver
 *  0.66 inch, 64x48 pixels, SSD1306 controller
 *
 *  Created: 2026-02-03
 *  © 2026 Marcel Sauder
 */


#include "display_b_066.h"

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// OLED 0.66" 64x48
#define SCREEN_WIDTH 64
#define SCREEN_HEIGHT 48
#define OLED_ADDR 0x3C

// ESP32 I2C Pins
#define I2C_SDA 21
#define I2C_SCL 22

static Adafruit_SSD1306 display(
    SCREEN_WIDTH,
    SCREEN_HEIGHT,
    &Wire,
    -1
);

bool display_b_066_init() {
    Wire.begin(I2C_SDA, I2C_SCL);

    if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
        return false;
    }

    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.display();

    return true;
}

void display_b_066_render(const char* line1, const char* line2) {
    display.clearDisplay();
    display.setCursor(0, 0);

    if (line1) display.println(line1);
    if (line2) display.println(line2);

    display.display();
}

