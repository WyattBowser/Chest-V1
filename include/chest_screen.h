#pragma once
#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "gif_handler.h"

class ChestScreen {
public:

  ChestScreen();

  void setup();

  void update();

private:
  bool timeToUpdate();

  unsigned long rate_ms_ = 66;
  unsigned long last_update_ = millis();

  int address_ = 0x3C;
  uint8_t text_size_ = 1;
  int text_color_ = WHITE;
  const int16_t WIDTH = 128;
  const int16_t HEIGHT = 64;
  const int OLED_RESET = -1;

  Adafruit_SSD1306 screen_;
  GifHandler gif_handler;
};