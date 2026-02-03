//
//  display_b_066.h
//  
//
//  Created by Marcel Sauder on 03.02.2026.
//
#pragma once

// Display B – OLED 0.66" 64x48
// Reine Hardware-Ausgabe, keine Logik

bool display_b_066_init();
void display_b_066_render(const char* line1, const char* line2);

