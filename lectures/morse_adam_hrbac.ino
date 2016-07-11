/*
 * Morse - Adam Hrbáč
 * Created by Adam Hrbáč
 * RoboCamp 2016
 * RoboticsBrno
 * www.robotikabrno.cz
 *
 * Description:
 * Convertor from text to morse. 
 */

void setup(){
  Serial.begin(9600);
  pinMode(13,OUTPUT);
}

void loop(){
  while(Serial.available() > 0){ //dokud jsou na vstupu znaky bezi smyck
    char znak = Serial.read(); // prijeti znaku
    String out = toMorse(znak); // prevod znaku
    blick((out=="?")?"":out); //blikani, prazdny string pri chybe prevodu
    Serial.write((out+"/").c_str()); //vypis
  }
}

//blikne podle retezce z "." a ","
void blick(String param){ 
  for(int i = 0; i<param.length(); i++){ //postupny pruchod vsemi znaky
    digitalWrite(13,HIGH); //rozsviceni diody
    delay(('.'==param.charAt(i))?200:500); //pokud je znak ".", je spozdeni 200ms, jinak 500ms
    digitalWrite(13,LOW);  //zhasnuti diody
    delay(400);
  }
}

//prevod do morseovky
String toMorse(char in){
  in = toupper(in); //prevod na velka pismena
  String out="?"; //chybovy znak
  switch(in){ //switch se znaky
    case 'A':
      out=".-";
    break;
    case 'B':
      out="-...";
    break;
    case 'C':
      out="-.-.";
    break;
    case 'D':
      out="-..";
    break;
    case 'E':
      out=".";
    break;
    case 'F':
      out="..-.";
    break;
    case 'G':
      out="--.";
    break;
    case 'H':
      out="....";
    break;
    case 'I':
      out="..";
    break;
    case 'J':
      out=".---";
    break;
    case 'K':
      out="-.-";
    break;
    case 'L':
      out=".-..";
    break;
    case 'M':
      out="--";
    break;
    case 'N':
      out="-.";
    break;
    case 'O':
      out="---";
    break;
    case 'P':
      out=".--.";
    break;
    case 'Q':
      out="--.-";
    break;
    case 'R':
      out=".-.";
    break;
    case 'S':
      out="...";
    break;
    case 'T':
      out="-";
    break;
    case 'U':
      out="..-";
    break;
    case 'V':
      out="...-";
    break;
    case 'W':
      out=".--";
    break;
    case 'X':
      out="-..-";
    break;
    case 'Y':
      out="-.--";
    break;
    case 'Z':
      out="--..";
    break;
    case '0':
      out="-----";
    break;
    case '1':
      out=".----";
    break;
    case '2':
      out="..---";
    break;
    case '3':
      out="...--";
    break;
    case '4':
      out="....-";
    break;
    case '5':
      out=".....";
    break;
    case '6':
      out="-....";
    break;
    case '7':
      out="--...";
    break;
    case '8':
      out="---..";
    break;
    case '9':
      out="----.";
    break;
     
  }
  return out;
}
