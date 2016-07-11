/*
 * Example Morse 03
 * Created by Jarek Paral
 * RoboCamp 2016
 * RoboticsBrno
 * www.robotikabrno.cz
 *
 * Description:
 * Convertor from text to morse. 
 */

int pinLed = 13;
char ch;

int dotTime = 500;    // .
int hashTime = 1000;  // -
int spaceDotHashTime = 500;
int charTime = 1500;

void blink(char ch) {
  digitalWrite(pinLed, HIGH);
  if(ch == '.')
    delay(dotTime);
  else // ch == '-'
    delay(hashTime);
  digitalWrite(pinLed, LOW);
  delay(spaceDotHashTime);    
}

void blinking(String str) {
  for(int i = 0; i < str.length(); i++)
  {
    blink(str[i]);  
  }
}

void setup() {
  pinMode(pinLed, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if(Serial.available())
  {
    ch = Serial.read();

    switch(ch){
      case 'A':
        Serial.print(".-");
        digitalWrite(pinLed, HIGH);
        delay(dotTime);
        digitalWrite(pinLed, LOW);
        delay(spaceDotHashTime);
        digitalWrite(pinLed, HIGH);
        delay(hashTime);
        digitalWrite(pinLed, LOW);
        delay(spaceDotHashTime);
        break;
      case 'B':
        Serial.print("-...");
        blink('-');
        blink('.');
        blink('.');
        blink('.');
        break;
      case 'C':
        Serial.print("-.-.");
        blinking("-.-.");
        break;
      case 'D':
        Serial.print("-..");
        blinking("-..");
        break;
      case 'J':
        Serial.print(".---"); 
        blinking(".---");
        break;
      case 'O':
        Serial.print("---"); 
        blinking("---");
        break;
    }
    
    delay(charTime - spaceDotHashTime);
  }
}