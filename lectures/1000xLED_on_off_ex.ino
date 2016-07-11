/*
 * Example of 1000x set on/off LED
 * Created by Jarek Paral
 * RoboticsCamp 2016
 * RoboticsBrno
 * www.robotikabrno.cz
 */

int pinLed = LED_BUILTIN;

void setup() {
  pinMode(pinLed, OUTPUT);
  for(int i = 0; i < 1000; i++)
  {
     digitalWrite(pinLed, HIGH);
     delay(100);
     digitalWrite(pinLed, LOW);
     delay(100);    
  } 
}

void loop() {
}