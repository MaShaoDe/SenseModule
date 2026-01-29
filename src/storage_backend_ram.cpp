#include "storage_backend_ram.h"

StorageBackendRAM::StorageBackendRAM()
: write_index(0),
  record_count(0)
{
}

bool StorageBackendRAM::write(const StorageRecord& record)
{
#if STORAGE_RAM_ALLOW_OVERWRITE == 0

    // Strict mode: reject when full
    if (record_count >= CAPACITY) {
        return false;
    }

    // Defensive indexing: always stay in bounds
    buffer[record_count] = record;
    record_count++;
    write_index = record_count;

    return true;

#else

    // Overwrite mode: ring buffer behavior
    buffer[write_index] = record;

    write_index++;
    if (write_index >= CAPACITY) {
        write_index = 0;
    }

    if (record_count < CAPACITY) {
        record_count++;
    }

    return true;

#endif
}

uint16_t StorageBackendRAM::capacity() const
{
    return CAPACITY;
}

uint16_t StorageBackendRAM::count() const
{
    return record_count;
}

void StorageBackendRAM::reset()
{
    write_index  = 0;
    record_count = 0;
}
