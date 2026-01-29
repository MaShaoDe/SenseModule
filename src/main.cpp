#include <Arduino.h>

#include "sensecore_storage.h"
#include "storage_backend_ram.h"
#include "sensecore_time.h"

void setup()
{
    Serial.begin(115200);
    delay(500);

    Serial.println();
    Serial.println("SenseModule started (SenseCore time module)");
}

void loop()
{
    uint32_t now = sensecore_time_now();

    StorageRecord r;
    r.timestamp = now;
    r.source_id = 1;     // placeholder role id
    r.type_id   = 1;     // placeholder measurement type
    r.value     = 25000; // placeholder value
    r.flags     = 0;

    bool ok = storage_write(r);

    Serial.print("t=");
    Serial.print(now);
    Serial.print(" write=");
    Serial.print(ok);
    Serial.print(" count=");
    Serial.println(storage_count());

    delay(1000);
}
