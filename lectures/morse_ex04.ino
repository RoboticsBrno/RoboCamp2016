/*
 * Example Morse 04
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

int dotTime = 500;
int hashTime = 1000;
int spaceTime = 1500;
int charTime = 500;
int wordTime = 2000;

String morse_letter[] = 
{
  ".-"  , // A
  "-...", // B
  "-.-.", // C
  "-.." , // D
  "."   , // E
  "..-.", // F
  "--." , // G
  "....", // H
  ".."  , // I
  ".---", // J
  "-.-" , // K
  ".-..", // L
  "--"  , // M
  "-."  , // N
  "---" , // O
  ".--.", // P
  "--.-", // Q
  ".-." , // R
  "..." , // S
  "-"   , // T
  "..-" , // U
  "...-", // V
  ".--" , // W
  "-..-", // X
  "-.--", // Y
  "--.."  // Z
};

String morse_num[] =
{
  "-----", // 0
  ".----", // 1
  "..---", // 2
  "...--", // 3
  "....-", // 4
  ".....", // 5
  "-....", // 6
  "--...", // 7
  "---..", // 8
  "----."  // 9
};

void blink(char ch) {
  Serial.write(ch);
  digitalWrite(pinLed, HIGH);
  if(ch == '.')
  {
    delay(dotTime);
  }
  else if(ch == '-')
  {
    delay(hashTime);
  }
  digitalWrite(pinLed, LOW);
  delay(spaceTime); 
}

void blinking(String str) {
  for(int i; i < str.length(); i++)
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
    if(isAlpha(ch))
      blinking(morse_letter[(ch | 32) - 'a']);
    else if(isDigit(ch))
      blinking(morse_num[ch - '0']);
    else if(ch == ' ')
    {
      Serial.write('|');
      delay(wordTime);
    }
    Serial.write('|');
    delay(charTime);
  }
}
