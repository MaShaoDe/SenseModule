#pragma once

typedef enum {
    SC_ROLE_BASE,
    SC_ROLE_SATELLITE,
    SC_ROLE_CONTROL
} sc_role_t;

typedef struct {
    sc_role_t role;
} sc_config_t;
