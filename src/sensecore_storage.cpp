#include "storage_backend_ram.h"

static StorageBackendRAM storage_backend;

bool storage_write(const StorageRecord& record)
{
    return storage_backend.write(record);
}

uint16_t storage_capacity()
{
    return storage_backend.capacity();
}

uint16_t storage_count()
{
    return storage_backend.count();
}
