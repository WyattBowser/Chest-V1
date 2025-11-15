#include "chest_screen.h"

ChestScreen::ChestScreen():screen_(WIDTH, HEIGHT, &Wire, -1) {};


void ChestScreen::setup() {
  screen_.setTextColor(WHITE);
  screen_.setTextSize(this->text_size_);

  Serial.println("Starting screen");
  if(!screen_.begin(SSD1306_SWITCHCAPVCC, address_)) {
    for(;;) {
      Serial.println(F("SSD1306 allocation failed"));
    } // Don't proceed, loop forever
  }
  Serial.println("Screen started");

  screen_.clearDisplay();
  //screen_.drawBitmap(0,0, gif_handler.getFrame(), WIDTH, HEIGHT, text_color_);
  //screen_.display();
  last_update_ = millis();
}

void ChestScreen::update() {
    if (timeToUpdate()) {
      screen_.clearDisplay();
      unsigned long time = millis();
      screen_.drawBitmap(0,0, gif_handler.getFrame(), WIDTH, HEIGHT, text_color_);
      screen_.display();
      Serial.println("Time: " + String(millis() - time));
      last_update_ = millis();
    }
}

bool ChestScreen::timeToUpdate() {
  return millis() - last_update_ >= rate_ms_;
}