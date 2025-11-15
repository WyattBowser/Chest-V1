#include <Adafruit_NeoPixel.h>

class LedController{
public: 
  LedController();
  void setRGB(uint8_t r, uint8_t g, uint8_t b);
  void off();

private:
  Adafruit_NeoPixel lights_;
  static constexpr int PIN = 2;
  static constexpr int NUM_LIGHTS = 12;
};