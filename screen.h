#ifndef SCREEN_H
#define SCREEN_H

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

#define HEART_WIDTH 7
#define HEART_HEIGHT 7
#define CYCLONE_WIDTH 128
#define CYCLONE_HEIGHT 16
#define COPYRIGHT_WIDTH 10
#define COPYRIGHT_HEIGHT 8
#define BULB_WIDTH 25
#define BULB_HEIGHT 16
#define COPYRIGHT_LOCATION 23
#define LEVEL_LOCATION 54
#define WIN_WORDS 7
#define LOSE_WORDS 6

#endif
