/*
   Example led (on/off) by serial communication
   Created by Jaroslav Páral
   RoboticsCamp 2016
   RoboticsBrno
   www.robotikabrno.cz
   
   Popis:
   Ovladani ledky pomoci seriove linky.
 */

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

char prijimanyZnak;

void loop() {
  if (Serial.available()) {
    prijimanyZnak = Serial.read();
    Serial.write(prijimanyZnak);

    if(prijimanyZnak == 'z') {
      // zapnu led kdyz prijde 'z'
      digitalWrite(LED_BUILTIN, HIGH);
    }
    else {
      // zhasnu led kdyz prijde cokoliv jineho
      digitalWrite(LED_BUILTIN, LOW);
    }
  }  
}
