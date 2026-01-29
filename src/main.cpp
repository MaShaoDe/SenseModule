#include <Arduino.h>

#include "sensecore/sensecore.h"
#include "sensecore/sc_config.h"

void setup()
{
    sc_config_t cfg;
    cfg.role = SC_ROLE_BASE;

    sensecore_init(cfg);
}

void loop()
{
    sensecore_run_cycle();
}
