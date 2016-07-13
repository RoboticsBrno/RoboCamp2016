#include <FastLED.h>

#include "DHT.h"

const int DATA_PIN = 2;
const int BUTTON_PIN = 3;
const int DHT_DATA_PIN = 4;
const int DHT_GND_PIN = 5;
const int DHT_VCC_PIN = 6;

const int LED_COUNT = 24;
const int LED_BRIGHTNESS = 255;

const int MIN_TEMP = 15;
const int MAX_TEMP = 40;
const int TEMP_HUE_START = 0;
const int TEMP_HUE_END = 35;
const int HUM_HUE_START = 165;
const int HUM_HUE_END = 133;

int phase = 0;
int phase_step = 1;
int phase_inc = 2;

int ignore = 0;

enum Mode {HUMIDITY, TEMP, COLOR, LAST};
int mode = Mode::COLOR;

DHT dht(DHT_DATA_PIN, DHT11);

CRGB leds[LED_COUNT];

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, LED_COUNT);
  
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(DHT_GND_PIN, OUTPUT);
  digitalWrite(DHT_GND_PIN, LOW);
  pinMode(DHT_VCC_PIN, OUTPUT);
  digitalWrite(DHT_VCC_PIN, HIGH);

  dht.begin();

  Serial.begin(9600);
}

void do_humidity() {
  float humidity = dht.readHumidity();
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print("\n");

  for (int i = 0; i != LED_COUNT; i++) {
    int t = i * 100 / LED_COUNT;
    if (t < humidity) {
      leds[i] = CHSV(HUM_HUE_START + i * (HUM_HUE_END - HUM_HUE_START) / LED_COUNT, 255, LED_BRIGHTNESS);
    }
    else {
      leds[i] = CHSV(0, 0, 0);
    }
  }
  FastLED.show();
}

void do_temp() {
  float temp = dht.readTemperature();
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.print("\n");

  for (int i = 0; i != LED_COUNT; i++) {
    int t = MIN_TEMP + i * (MAX_TEMP - MIN_TEMP) / LED_COUNT;
    if (t < temp) {
      leds[i] = CHSV(TEMP_HUE_START + i * (TEMP_HUE_END - TEMP_HUE_START) / LED_COUNT, 255, LED_BRIGHTNESS);
    }
    else {
      leds[i] = CHSV(0, 0, 0);
    }
  }
  FastLED.show();
}

void do_colors() {
  for (int i = 0; i != LED_COUNT; i++) {
    leds[i] = CHSV(phase + i * phase_inc, 255, LED_BRIGHTNESS);
  }
  phase += phase_step;
  FastLED.show();
}

void loop() {
  if (digitalRead(BUTTON_PIN) == LOW && ignore == 0) {
    ignore = 10;
    mode++;
    if (mode == Mode::LAST)
      mode = Mode::HUMIDITY;   
  }

  switch(mode) {
    case Mode::HUMIDITY:
      do_humidity();
      break;
    case Mode::TEMP:
      do_temp();
      break;
    case Mode::COLOR:
      do_colors();
      break;
  }
  
  delay(30);
  if (ignore != 0)
    ignore--;
}

