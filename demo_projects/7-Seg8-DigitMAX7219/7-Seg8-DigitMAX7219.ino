/*
 * 7-Seg 8-Digit MAX7219
 * RoboticsBrno 2016
 * www.robotikabrno.cz
 * version 1.0
 * 2016_07_06
 * Copy and modify from: https://codebender.cc/sketch:190454#7-Seg%208-Digit%20MAX7219.ino
 *
 * Arduino Nano -> 7-Seg 8-Digit MAX7219:
 * 5V   -> VCC
 * GND  -> GND
 * D10  -> CS
 * D11  -> CLK
 * D12  -> DIN
 */

#include "LedControl.h" //  need the library for control MAX7219

// LedControl(DIN,CLK,CS,numDevices)
/*
 * DIN  (dataPin)   pin on the Arduino where data gets shifted out
 * CLK  (clockPin)  pin for the clock
 * CS   (csPin)     pin for selecting the device 
 * numDevices       number of devices (MAX7219) which you have connected (min 1, max 8)
 */
LedControl lc=LedControl(12,11,10,1); // lc is our object
// pin 12 (D12) is connected to the DIN
// pin 11 (D11) is connected to the CLK
// pin 10 (D10) is connected to the CS
// 1 as we are using only one MAX7219 (min 1, max 8)

char characters[] = {'A','b','c','d','E','F','H','L','P'};

void setup()
{
  // the first number (now zero) is ID of device which you will control
  // it is zero for first chip, one for second chip, ....., numDevice - 1 for last chip
  lc.shutdown(0,false);// turn off power saving, enables display
  lc.setIntensity(0,1);// sets brightness (0~15 possible values)
  lc.clearDisplay(0);// clear screen
}

void loop()
{
  for (int a=0; a<8; a++)
  {
    lc.setDigit(0,a,a,false);  // device 0, digit = a, value a, boolean dp = decimal point)
    delay(100);
  }
  for (int a=0; a<8; a++)
  {
    lc.setDigit(0,a,8,true);      // set all to 8 with DP (decimal point)
    delay(100);
  }
  for (int a=0; a<8; a++)
  {
    lc.setDigit(0,a,0,false);  // zero out with no DP
    delay(100);
  }
  for (int a=0; a<8; a++)
  {
    lc.setChar(0,a,' ',false);  // blank out with no DP
    delay(100);
  }
  for (int a=0; a<8; a++)
  {
    lc.setChar(0,a,'-',false);   // dash out with no DP
    delay(100);
  }
  for (int a=0; a<8; a++)
  {
    lc.setChar(0,a,' ',false);
    delay(100);
  }
  for (int a=0; a<8; a++)
  {
    lc.setChar(0,7-a,characters[a],false);
    delay(100);
  }
}
