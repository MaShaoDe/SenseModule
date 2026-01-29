#pragma once

#include <stdint.h>
#include <stdbool.h>
#include "sensecore_config.h"

struct StorageRecord {
    uint32_t timestamp;
    uint16_t source_id;
    uint16_t type_id;
    int32_t  value;
    uint8_t  flags;
};

class StorageBackendRAM {
public:
    static constexpr uint16_t CAPACITY = STORAGE_RAM_CAPACITY;

    StorageBackendRAM();

    bool     write(const StorageRecord& record);
    uint16_t capacity() const;
    uint16_t count() const;

    void reset();

private:
    StorageRecord buffer[CAPACITY];
    uint16_t write_index;
    uint16_t record_count;
};
