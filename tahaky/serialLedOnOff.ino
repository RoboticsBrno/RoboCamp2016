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

    if(prijimanyZnak == 'z' || prijimanyZnak == 'Z') {
      // zapnu led kdyz prijde 'z' nebo 'Z'
      digitalWrite(LED_BUILTIN, HIGH);
    }
    else if(prijimanyZnak == 'v' || prijimanyZnak == 'V') {
      // zhasnu led kdyz prijde 'v' nebo 'V'
      digitalWrite(LED_BUILTIN, LOW);
    }
  }  
}
