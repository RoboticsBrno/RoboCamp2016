/*
   Example led blinking (on/off) by serial communication
   Created by Jaroslav Páral
   RoboticsCamp 2016
   RoboticsBrno
   www.robotikabrno.cz
   
   Popis:
   Ovladani blikani ledky pomoci seriove linky.
 */

void setup() 
{
  pinMode(LED_BUILTIN, OUTPUT); // nastaveni pinu LED_BUILTIN na vystupni
  Serial.begin(9600); // zapnuti seriove linky
}

char prijimanyZnak; // promena pro prijimani znaku po seriove lince
bool blikaniZapnutoVypnuto = false; // false == 0; true != 0 (napr. -4, 2, 1000)

void loop() 
{
  if (Serial.available()) 
  {
    prijimanyZnak = Serial.read();  // cteni znaku ze seriove linky

    if(prijimanyZnak == 'z' || prijimanyZnak == 'Z') // porovnani prijateho znaku
    {
      blikaniZapnutoVypnuto = true;
      Serial.println("Blikani - zapnuto ('z')");
    }
    else if(prijimanyZnak == 'v' || prijimanyZnak == 'V') 
    {
      blikaniZapnutoVypnuto = false;
      Serial.println("Blikani - vypnuto ('v')"); 
    }    
    else
      Serial.println("Neznamy prikaz");
  }  
  if(blikaniZapnutoVypnuto == true) 
  {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);
  }
}
