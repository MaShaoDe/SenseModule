#pragma once

#include <stdint.h>
#include "storage_backend_ram.h"

bool     storage_write(const StorageRecord& record);
uint16_t storage_capacity();
uint16_t storage_count();
