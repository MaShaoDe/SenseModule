#include <Arduino.h>
#include "sensecore.h"

static sc_config_t current_config;

void sensecore_init(const sc_config_t& config)
{
    current_config = config;

    Serial.begin(115200);
    Serial.println("SenseCore init");
}

void sensecore_run_cycle()
{
    // absichtlich leer
}
