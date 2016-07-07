#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "TimerOne.h"

#define COUNTER_PIN 2

// address 0x27 a 16 chars on 2 lines
LiquidCrystal_I2C lcd(0x27,16,2);

uint32_t g_counter = 0;
uint32_t lastTenMem[10];
int lastTenPointer = 0;
uint32_t oneSec = 0;
uint32_t tenSec = 0;

void ISR_counter()
{
  g_counter++;
}

void ISR_timer()
{
  static int loopCount = 0;
  lastTenMem[loopCount] = g_counter;
  oneSec = g_counter;
  tenSec = 0;
  for(int i=0; i<10; i++)
    tenSec += lastTenMem[i];
  
  g_counter = 0;
  loopCount++;
  if(loopCount % 10 == 0)
    loopCount = 0;
}

void setup()
{
  lcd.init();
  lcd.backlight();
  for(int i=0;i<10;i++)
    lastTenMem[i] = 0;
  attachInterrupt(digitalPinToInterrupt(COUNTER_PIN), ISR_counter, RISING);
  Timer1.initialize(1000000);
  Timer1.attachInterrupt(ISR_timer);
}

void loop()
{
  lcd.setCursor(0,0);
  lcd.print("One sec: ");
  lcd.print(oneSec);
  lcd.print("     ");

  lcd.setCursor(0,1);
  lcd.print("Ten sec: ");
  lcd.print(tenSec);
  lcd.print("     ");
    
  delay(1000);
}
