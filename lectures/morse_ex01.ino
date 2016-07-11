/*
 * Example Morse 01
 * Created by Jarek Paral
 * RoboCamp 2016
 * RoboticsBrno
 * www.robotikabrno.cz
 */

int pinLed = 13;
char ch;

int dotTime = 500;
int hashTime = 1000;
int spaceTime = 1500;
int charTime = 2000;

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
        delay(spaceTime);
        digitalWrite(pinLed, HIGH);
        delay(hashTime);
        digitalWrite(pinLed, LOW);
        break;
      case 'B':
        Serial.print("-...");
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
    
    delay(charTime);
}
