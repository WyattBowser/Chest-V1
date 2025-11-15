#include "gif_handler.h"

GifHandler::GifHandler() {
  sd_init_successful_ = SD.begin(CS);
  if(sd_init_successful_) {
    file = SD.open(FILE_NAME);
  }
}

unsigned char* GifHandler::getFrame() {
  
  if (!sd_init_successful_) {
    Serial.println("Cannot init SD card reader");
    return krayt_logo_;
  }

  if (!file) {
    Serial.println("Could not open file: " + FILE_NAME);
    return krayt_logo_;
  }

  //This will restart the current gif
  if (file.peek() == -1) {
    Serial.println("EOF reached. Restarting");
    file = SD.open(FILE_NAME);
  }
 
  file.readBytes(frame_, FRAME_PIXEL_COUNT);

  return frame_;
}