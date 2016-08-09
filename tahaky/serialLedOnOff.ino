/*
   Example led (on/off) by serial communication
   Created by Jaroslav Páral
   RoboticsCamp 2016
   RoboticsBrno
   www.robotikabrno.cz
   
   Popis:
   Ovladani ledky pomoci seriove linky.
 */

void setup() 
{
  pinMode(LED_BUILTIN, OUTPUT); // nastaveni pinu LED_BUILTIN na vystupni
  Serial.begin(9600); // zapnuti seriove linky
}

char prijimanyZnak; // promena pro prijimani znaku po seriove lince

void loop() 
{
  if (Serial.available()) 
  {
    prijimanyZnak = Serial.read();  // cteni znaku ze seriove linky
    Serial.write(prijimanyZnak);    // odeslani prijateho znaku zpet do PC

    if(prijimanyZnak == 'z' || prijimanyZnak == 'Z') // porovnani prijateho znaku
    {
      // zapnu led kdyz prijde 'z' nebo 'Z'
      digitalWrite(LED_BUILTIN, HIGH);
    }
    else if(prijimanyZnak == 'v' || prijimanyZnak == 'V') 
    {
      // zhasnu led kdyz prijde 'v' nebo 'V'
      digitalWrite(LED_BUILTIN, LOW);
    }
  }  
}
