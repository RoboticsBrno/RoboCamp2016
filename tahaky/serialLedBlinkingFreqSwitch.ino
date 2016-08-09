/*
   Example led blinking (on/off + freq) with switch by serial communication
   Created by Jaroslav Páral
   RoboticsCamp 2016
   RoboticsBrno
   www.robotikabrno.cz
   
   Popis:
   Ovladani blikani ledky a jeji frekvence se switchem pomoci seriove linky.
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

    switch(prijimanyZnak)
    {
      case 'z':
      case 'Z':
        blikaniZapnutoVypnuto = true;
        Serial.println("Blikani - zapnuto ('z' nebo 'Z')");
        break;
      case 'v':
      case 'V':
        blikaniZapnutoVypnuto = false;
        Serial.println("Blikani - vypnuto ('v' nebo 'V')"); 
        break;
      case 'p':
      case 'P':
        delkaPauzy += 100;
        Serial.print("Blikani - pomaleji ('p' nebo 'P'): "); 
        Serial.println(delkaPauzy);
        break;
      case 'r':
      case 'R':     
        delkaPauzy -= 100;
        Serial.print("Blikani - rychleji ('r' nebo 'R'): "); 
        Serial.println(delkaPauzy);
        break;
      default:
        Serial.println("Neznamy prikaz");
        break;
    }
  }  
  if(blikaniZapnutoVypnuto == true) 
  {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(delkaPauzy);
    digitalWrite(LED_BUILTIN, LOW);
    delay(delkaPauzy);
  }
}
