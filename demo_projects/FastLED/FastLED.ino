#include "FastLED.h"

CRGB leds[1];
void setup() { FastLED.addLeds<NEOPIXEL, 8>(leds, 1); }
void loop() { 
  leds[0] = CRGB(255,255,255); FastLED.show(); delay(500); 
  leds[0] = CRGB(0,0,0); FastLED.show(); delay(100);
}
