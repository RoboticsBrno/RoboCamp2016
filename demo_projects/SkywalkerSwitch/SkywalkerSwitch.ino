#include <Servo.h>

Servo servo;

void setup() {
  pinMode(13, OUTPUT);
  pinMode(11, INPUT);
  digitalWrite(11, HIGH);
  servo.attach(12);

  servo.write(20);
  digitalWrite(13, HIGH);
  delay(100);
  digitalWrite(13, LOW);
  
  while(digitalRead(11) == LOW);
}


void loop() {
  while(digitalRead(11) == LOW)
  {
    servo.detach();
    digitalWrite(12, digitalRead(10));
  }
  servo.attach(12);
  servo.write(20);
}
