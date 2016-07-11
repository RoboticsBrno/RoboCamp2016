/*
 * Example Morse 02
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

void setup() {
  pinMode(pinLed, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if(Serial.available())
  {
    ch = Serial.read();

    switch(ch)
    {
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
        break;
      case 'D':
        Serial.print("-..");
        break;
      case 'J':
        Serial.print(".---"); 
        break;
      case 'O':
        Serial.print("---"); 
        break;
    }
    
    delay(charTime - spaceDotHashTime);
  }
}
