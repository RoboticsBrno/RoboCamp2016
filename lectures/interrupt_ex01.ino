/*
   Example interupt 01
   Created by Jarek Paral
   RoboticsCamp 2016
   RoboticsBrno
   www.robotikabrno.cz
   
   Description:
   Measuring number of rising edge by interrupt on pin D2 (PIN2).
   
   Pinout:
   D3 (PIN3) connect with D2 (PIN2)
*/

int interruptPin = 2;
int outputPin = 3;
volatile int cnt = 0;

void counter() {
  cnt++; // same: cnt = cnt + 1; cnt += 1; ++cnt;
}

void setup() {
  pinMode(outputPin, OUTPUT);
  digitalWrite(outputPin, HIGH);
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(
    digitalPinToInterrupt(interruptPin),
    counter, RISING);

  Serial.begin(9600);

  for(int i = 0; i < 10; i++)
  {
     digitalWrite(outputPin, HIGH);
     delay(100);
     digitalWrite(outputPin, LOW);
     delay(100); 
     Serial.println(cnt);
  } 
}

void loop() {
  Serial.println(cnt); // end resul = 10
  delay(100);
}