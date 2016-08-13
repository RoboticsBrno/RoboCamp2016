/*
 * Pro zprovoznění tohoto programu potřebujete přidat knihovnu FastLED. 
 * Knihovnu lze přidat takto:
 * 1) V Arduino IDE, v horní liště, otevřete záložku 'Projekt'
 * 2) Přejdete na 'Přidat knihovnu'
 * 3) Kliknete na 'Spravovat knihovny ...'
 * 4) Otevře se 'Manažér knihoven' a do filtrovacího/vyhledávacího políčka zadáte 'FastLED'
 * 5) Měli byste vidět jednu knihovnu FastLED od Daniela Garcia, klikněte na ní a dejte instal
 * 6) Hotovo - můžete zkompilovat program a nahrát jej do Arduina
 */

#include <FastLED.h>

#define NUM_LEDS 3
#define DATA_PIN 11

CRGB leds[NUM_LEDS];

void setup() 
{
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}

void loop() 
{
  leds[0] = CRGB::Red;
  leds[1] = CRGB::Green;
  leds[2] = CRGB(0, 0, 255);
  FastLED.show();
  delay(500);
  leds[0] = CRGB::Black;
  leds[1] = CRGB::Black;
  leds[2] = CRGB(255, 255, 255);
  FastLED.show();
  delay(500);
}
