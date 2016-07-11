/*
   Example control LED by serial 01
   Created by Bedrich Said
   RoboticsCamp 2016
   RoboticsBrno
   www.robotikabrno.cz
   
   Popis:
   Ukazkove priklady na praci s pinem a seriovou linku.
 */

void setup() {
  // chci nastavit pin jako digitalni vstup/vystup
  pinMode(13, OUTPUT);  // 13 - cislo pinu (LEDka), INPUT/INPUT_PULLUP/OUTPUT
 
  // chci rozsvitit LEDku (zapsat na digitalni vystup, kde je pripojena)
  digitalWrite(13, HIGH); // 13 - cislo pinu (LEDka), HIGH/LOW
 
  // aktivuju seriovou linku na rychlost 9600 bitu za vterinu
  Serial.begin(9600);
 
  // poslu text/znak/cislo na seriovou linku.
  Serial.print("Tento text se vypise na seriovou linku.");
 
  // prectu jednu klavesu ze seriove linky, pokud zadna klavesa neni stisknuta, tak se do prijatyZnak ulozi -1
  int prijatyZnak = Serial.read();
}
 
void loop() {
  // chci precist stav tlacitka, do nejake promenne si ulozim jeho stav
  int stav = digitalRead(8);
 
  // LEDku nastavim podle toho, jestli je nebo neni zmacknute tlacitko
  digitalWrite(13, stav);
 
  // prectu anlogovou hodnotu na potenciometru z portu A2
  int hodnota = analogRead(2);
 
  // prectenou hodnotu ze senzoru/potenciometru poslu na seriovou linku a skocim na novy radek
  Serial.println(hodnota);
}