/*
 * Morse - Petr Kubica
 * Created by Petr Kubica
 * RoboCamp 2016
 * RoboticsBrno
 * www.robotikabrno.cz
 *
 * Description:
 * Convertor from text to morse. 
 */

void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

char in = 'a';

void loop() {
  if(Serial.available()) {
    in = Serial.read();
    String out = morseCoder(in);
    writeString(out);
    blinkMorse(out);
  }
}

void writeString(String stringData) {
  for (int i = 0; i < stringData.length(); i++) {
    Serial.write(stringData[i]);
  }
  Serial.write('\n');
}

void blinkMorse(String out) {
  for(int i = 0; i < out.length(); i++) {
    if(out.charAt(i) == '-') {
      digitalWrite(13, 1);
      delay(400);
      digitalWrite(13, 0);
      delay(100);
    }
    else if(out.charAt(i) == '.') {
      digitalWrite(13, 1);
      delay(100);
      digitalWrite(13, 0);
      delay(100);
    }
    else if(out == "error")
      digitalWrite(13, 1);
      delay(1000);
      digitalWrite(13, 0);
      delay(100);
  }
}

String morseCoder(char x) {
  x = tolower(x);
  switch (x) {
    case 'a':
    return ".-";
    break;
    case 'b':
    return "-...";
    break;
    case 'c':
    return "-.-.";
    break;
    case 'd':
    return "-..";
    break;
    case 'e':
    return ".";
    break;
    case 'f':
    return "..-.";
    break;
    case 'g':
    return "--.";
    break;
    case 'h':
    return "....";
    break;
    case 'i':
    return "..";
    break;
    case 'j':
    return ".---";
    break;
    case 'k':
    return "-.-";
    break;
    case 'l':
    return ".-..";
    break;
    case 'm':
    return "--";
    break;
    case 'n':
    return "-.";
    break;
    case 'o':
    return "---";
    break;
    case 'p':
    return ".--.";
    break;
    case 'q':
    return "--";
    break;
    case 'r':
    return ".-.";
    break;
    case 's':
    return "...";
    break;
    case 't':
    return "-";
    break;
    case 'u':
    return "..-";
    break;
    case 'v':
    return "...-";
    break;
    case 'w':
    return ".--";
    break;
    case 'x':
    return "...-";
    break;
    case 'y':
    return "-.--";
    break;
    case 'z':
    return "--..";
    break;
    default:
    return "error";
  }
}
