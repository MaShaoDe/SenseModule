#pragma once
#include <stdbool.h>

// Initialisierung
bool display_init();

// Render-Funktion
void display_render(
  int year, int month, int day,
  int hour, int minute, int second,
  float temp1,
  float temp2,
  float humidity
);
