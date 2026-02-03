//
//  display_b_066.h
//  
//
//  Created by Marcel Sauder on 03.02.2026.
//
#pragma once

class DisplayOLED066 {
public:
    bool begin();
    void clear();
    void drawText(int x, int y, const char* text);
    void update();
};
