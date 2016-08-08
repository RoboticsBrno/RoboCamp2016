/*
   Example variables and serial communication
   Created by Jaroslav Páral
   RoboticsCamp 2016
   RoboticsBrno
   www.robotikabrno.cz
   
   Popis:
   Ukazkove priklady na praci s promenyma a seriovou linku.
 */

void setup() {
  Serial.begin(9600);
}

bool pravdaNepravda; // 0 nebo 1
int celeCislo = 42; // -32768 <--> +32767 
float desetineCislo = 3.14; //  -3.4028235E+38 <--> 3.4028235E+38 
char znak = 'a'; // znak se zapisuje do apostrofu
char poleZnaku[] = "ahoj"; // textovy retezec se zapisuje do uvozovek

void loop() {
  Serial.println(pravdaNepravda);
  Serial.println(celeCislo);
  Serial.println(desetineCislo);
  Serial.println(znak);
  Serial.println(); // vytiskne prazdny novy radek
  delay(100);
}
