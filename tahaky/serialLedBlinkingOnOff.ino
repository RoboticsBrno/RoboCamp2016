/*
   Example led blinking (on/off) by serial communication
   Created by Jaroslav Páral
   RoboticsCamp 2016
   RoboticsBrno
   www.robotikabrno.cz
   
   Popis:
   Ovladani blikani ledky pomoci seriove linky.
 */

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

char prijimanyZnak;
bool blikaniZapnutoVypnuto = false; // false = 0

void loop() {
  if (Serial.available()) {
    prijimanyZnak = Serial.read();

    if(prijimanyZnak == 'z' || prijimanyZnak == 'Z') {
      blikaniZapnutoVypnuto = true;
      Serial.println("Blikani - zapnuto ('z')");
    }
    else if(prijimanyZnak == 'v' || prijimanyZnak == 'V') {
      blikaniZapnutoVypnuto = false;
      Serial.println("Blikani - vypnuto ('v')");
    }
    else
      Serial.println("Neznamy prikaz");
  }  

  if(blikaniZapnutoVypnuto == true) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);
  }
}
