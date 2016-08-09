/*
   Example led blinking (on/off + freq) by serial communication
   Created by Jaroslav Páral
   RoboticsCamp 2016
   RoboticsBrno
   www.robotikabrno.cz
   
   Popis:
   Ovladani blikani ledky a jeji frekvence pomoci seriove linky.
   Pri zmene frekvence nejprve zrychlujte a pak zpomalujte -> lepe pozorovatelne.
 */

void setup() 
{
  pinMode(LED_BUILTIN, OUTPUT); // nastaveni pinu LED_BUILTIN na vystupni
  Serial.begin(9600); // zapnuti seriove linky
}

char prijimanyZnak; // promena pro prijimani znaku po seriove lince
bool blikaniZapnutoVypnuto = false; // false == 0; true != 0 (napr. -4, 2, 1000)
int delkaPauzy = 500; // promena pro ovlivnovani frekvence blikani (v milisekundach) 

void loop() 
{
  if (Serial.available()) 
  {
    prijimanyZnak = Serial.read();  // cteni znaku ze seriove linky

    if(prijimanyZnak == 'z' || prijimanyZnak == 'Z') // porovnani prijateho znaku
    {
      blikaniZapnutoVypnuto = true;
      Serial.println("Blikani - zapnuto ('z' nebo 'Z')");
    }
    else if(prijimanyZnak == 'v' || prijimanyZnak == 'V') 
    {
      blikaniZapnutoVypnuto = false;
      Serial.println("Blikani - vypnuto ('v' nebo 'V')"); 
    }    
    else if(prijimanyZnak == 'p' || prijimanyZnak == 'P') 
    {
      delkaPauzy = delkaPauzy + 100; // delkaPauzy += 100;
      Serial.print("Blikani - pomaleji ('p' nebo 'P'): "); 
      Serial.println(delkaPauzy);
    }    
    else if(prijimanyZnak == 'r' || prijimanyZnak == 'R') 
    {
      delkaPauzy = delkaPauzy - 100; // delkaPauzy -= 100;
      Serial.print("Blikani - rychleji ('r' nebo 'R'): "); 
      Serial.println(delkaPauzy);
    }
    else
      Serial.println("Neznamy prikaz");
  }  
  if(blikaniZapnutoVypnuto == true) 
  {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(delkaPauzy);
    digitalWrite(LED_BUILTIN, LOW);
    delay(delkaPauzy);
  }
}
