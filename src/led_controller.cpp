#include "led_controller.h"

LedController::LedController() : lights_(NUM_LIGHTS, PIN, NEO_RGB + NEO_KHZ800) {
  lights_.begin();
}

void LedController::setRGB(uint8_t r, uint8_t g, uint8_t b)
{
  lights_.setBrightness(100);
  for (int i = 0; i < NUM_LIGHTS; i++) {
    //For some reason r and g are switched here
    lights_.setPixelColor(i, lights_.Color(g, r, b));
  }
  lights_.show();
}

void LedController::off() {
  lights_.clear();
  lights_.show();
}