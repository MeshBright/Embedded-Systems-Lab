#include "SevSeg.h"
SevSeg sevseg; // Initiate a sevseg object

void setup() {
  byte numDigits = 4;

  // MAPPING:
  // Digit 1 -> Pin 10, Digit 2 -> Pin 11, Digit 3 -> Pin 12, Digit 4 -> Pin 13
  byte digitPins[] = {10, 11, 12, 13}; 

  // MAPPING: 
  // a->2, b->3, c->4, d->5, e->6, f->7, g->8, dp->9
  byte segmentPins[] = {2, 3, 4, 5, 6, 7, 8, 9}; 

  bool resistorsOnSegments = true; // 'true' if resistors are on segment pins
  
  // IMPORTANT: If your display is Common Anode, change this to COMMON_ANODE
  byte hardwareConfig = COMMON_CATHODE; 
  
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
  sevseg.setBrightness(90);
}

void loop() {
  sevseg.setNumber(3110, 1); // Display 1234
  sevseg.refreshDisplay();   // This MUST be called repeatedly
}