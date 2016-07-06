#include "FastLED.h"
#include "DFRobotColorSensor.h"

CRGB leds[1];
ColorSensor cs;

void setup()
{
  FastLED.addLeds<NEOPIXEL, 8>(leds, 1);
  cs.begin(3, 4, 5, 6, 2);
  Serial.begin(9600);
}

void loop()
{
  leds[0] = CRGB(cs.red(), cs.green(), cs.blue());
  FastLED.show();
  
  Serial.print("RGB:\t");
  Serial.print(leds[0].red,DEC);
  Serial.print("\t");
  Serial.print(leds[0].green,DEC);
  Serial.print("\t");
  Serial.print(leds[0].blue,DEC);
  Serial.println();
  
  delay(50);
}

