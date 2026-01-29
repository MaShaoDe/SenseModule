// Sense-Module Core v1 – main.cpp
// © Marcel Sauder · Sense Module · January 2026

#include <Arduino.h>
#include <Wire.h>

// -----------------------------------------------------------------------------
// Configuration
// -----------------------------------------------------------------------------

#define SERIAL_BAUDRATE 115200

// I²C default pins for ESP32 DevKitC V3
#define I2C_SDA_PIN 21
#define I2C_SCL_PIN 22

// Status LED pins
#define LED_GREEN_PIN 16
#define LED_RED_PIN   17

// User button pin
#define USER_BUTTON_PIN 27

// -----------------------------------------------------------------------------
// Global state
// -----------------------------------------------------------------------------

bool system_ok = true;

// -----------------------------------------------------------------------------
// Helper functions
// -----------------------------------------------------------------------------

void init_serial()
{
    Serial.begin(SERIAL_BAUDRATE);
    delay(200);
    Serial.println();
    Serial.println("[Sense-Module Core] Booting...");
}

void init_gpio()
{
    pinMode(LED_GREEN_PIN, OUTPUT);
    pinMode(LED_RED_PIN, OUTPUT);

    pinMode(USER_BUTTON_PIN, INPUT_PULLUP);

    digitalWrite(LED_GREEN_PIN, LOW);
    digitalWrite(LED_RED_PIN, LOW);
}

void init_i2c()
{
    Wire.begin(I2C_SDA_PIN, I2C_SCL_PIN);
    Serial.println("[I2C] Bus initialised");
}

void i2c_scan()
{
    Serial.println("[I2C] Scanning bus...");

    uint8_t count = 0;
    for (uint8_t address = 1; address < 127; address++)
    {
        Wire.beginTransmission(address);
        if (Wire.endTransmission() == 0)
        {
            Serial.print("  Found device at 0x");
            if (address < 16) Serial.print("0");
            Serial.println(address, HEX);
            count++;
        }
    }

    if (count == 0)
    {
        Serial.println("  No I2C devices found");
        system_ok = false;
    }
    else
    {
        Serial.print("  Total devices: ");
        Serial.println(count);
    }
}

// -----------------------------------------------------------------------------
// Arduino entry points
// -----------------------------------------------------------------------------

void setup()
{
    init_serial();
    init_gpio();
    init_i2c();

    i2c_scan();

    if (system_ok)
    {
        digitalWrite(LED_GREEN_PIN, HIGH);
        Serial.println("[System] Core initialisation OK");
    }
    else
    {
        digitalWrite(LED_RED_PIN, HIGH);
        Serial.println("[System] Core initialisation FAILED");
    }
}

void loop()
{
    // Simple heartbeat via green LED
    digitalWrite(LED_GREEN_PIN, HIGH);
    delay(500);
    digitalWrite(LED_GREEN_PIN, LOW);
    delay(500);

    // User button test
    if (digitalRead(USER_BUTTON_PIN) == LOW)
    {
        Serial.println("[Input] User button pressed");
        delay(300); // crude debounce
    }
}
