#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library
#include <SPI.h>
#include <sram.h>

const int TFT_CS = 10;
const int TFT_RST = 9;
const int TFT_DC = 8;

const int GM_PIN = 2;
const int RAM_CS_PIN = 3;

const uint16_t VEC_LEN = 128;
const unsigned long SAMPLE_NUM = 250;
const unsigned long SAMPLE_TIME = 5;

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS,  TFT_DC, TFT_RST);
SRAM ram(RAM_CS_PIN); 

uint8_t readout_vector[VEC_LEN];
uint8_t summary_vector[VEC_LEN];
unsigned long last_readout = 0;
uint8_t phase = 0;
uint8_t sample = 0;

void reset_vector(uint8_t* vec) {
  for (int i = 0; i != VEC_LEN; i++)
    vec[i] = 0;
}

void write_vector(uint16_t vector_num, uint8_t* source, bool verb = false) {
  uint16_t addr = VEC_LEN * vector_num;
  
  if (verb) {
    Serial.println(addr);
    Serial.print("Writing: ");
  }
  for (int i = 0; i != VEC_LEN; i++, addr++) {
    ram.writeByte(addr, source[i]);
    if (verb) {
      Serial.print(source[i]);
      Serial.print("|");
      Serial.print(ram.readByte(addr));
      Serial.print(" ");
    }
  }
  
  if (verb) {
    Serial.print("\n");
  }
}

void read_vector(uint16_t vector_num, uint8_t* dest, bool verb = false) {
  uint16_t addr = VEC_LEN * vector_num;
  if (verb)
    Serial.print("Reading: ");
  for (int i = 0; i != VEC_LEN; i++, addr++) {
    dest[i] = ram.readByte(addr);
    if (verb) {
      Serial.print(dest[i]);
      Serial.print(" ");
    }
  }
  if (verb) {
    Serial.print("\n");
  }
}

void add_vectors(uint8_t *v1, uint8_t* v2) {
  for (int i = 0; i != VEC_LEN; i++)
    v1[i] += v2[i];
}

uint8_t vector_max(uint8_t* vec) {
  uint8_t m = vec[0];
  for (int i = 1; i != VEC_LEN; i++)
    m = max(m, vec[i]);
  return m;
}

void on_pulse() {
  unsigned long stamp = millis();
  unsigned long diff = stamp - last_readout;
  diff /= 100;
  readout_vector[diff]++;
  last_readout = stamp;
}

void draw_histogram(uint8_t* vec, uint16_t m) {
  for(int i = 0; i != 128; i++) {
    uint16_t h = 100 * vec[i] / m;
    tft.drawFastVLine(i, 25, tft.height() - h, ST7735_BLACK);
    tft.drawFastVLine(i, tft.height() - h, tft.height(), ST7735_GREEN);
  }
}

void draw_info(uint16_t m) {
  tft.setCursor(0, 0);
  tft.setTextColor(ST7735_RED, ST7735_BLACK);
  tft.setTextWrap(false);
  tft.print("Maximum: ");
  tft.print(m);
  tft.println("     ");
  tft.println("Time width: 12.8 s");
  tft.print("Data from last ");
  unsigned long t = millis();
  if (t > SAMPLE_NUM * SAMPLE_TIME * 1000)
    t = SAMPLE_NUM * SAMPLE_TIME;
  else
    t /= 1000;
  tft.print(t);
  tft.println(" s     ");
}

void setup() {
  Serial.begin(9600);
  
  tft.initR(INITR_144GREENTAB);
  tft.fillScreen(ST7735_BLACK);

  ram.begin();
  for(uint16_t i = 0; i != 32u * 1024u; i++)
    ram.writeByte(i, 0);

  reset_vector(readout_vector);

  attachInterrupt(digitalPinToInterrupt(GM_PIN), on_pulse, RISING);
}

void loop() {
  if (phase == SAMPLE_TIME) {
    phase = 0;

    cli();
    write_vector(sample, readout_vector);
    reset_vector(readout_vector);
    sei();
    sample++;
    if (sample == SAMPLE_NUM)
      sample = 0;

    reset_vector(summary_vector);
    uint8_t s[VEC_LEN];
    for (uint8_t i = 0; i != SAMPLE_NUM; i++) {
      read_vector(i, s);
      add_vectors(summary_vector, s);
    }
  }
  else {
    phase++;
  }
  
  // Draw histogram
  uint16_t m = vector_max(summary_vector);
  draw_histogram(summary_vector, m);

  // Draw text on display
  draw_info(m);
  
  delay(1000);
}
