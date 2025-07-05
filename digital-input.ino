#include <Servo.h>
Servo myservo;


int pulsadorCeroGrados = 7; 
int pulsadorCientochentaGrados = 6;
int pinServo = 2;
int pinLed = 4;

void setup() {
  // Entradas digitales
  pinMode(pulsadorCeroGrados, INPUT_PULLUP);
  pinMode(pulsadorCientochentaGrados, INPUT_PULLUP);
  pinMode(pinLed, OUTPUT);


  // Configurando Servo
  myservo.attach(pinServo);
  myservo.write(90);// move servos to center position -> 90°
}

void loop() {
  // Configurando ángulos y leds
  if (digitalRead(pulsadorCeroGrados) == LOW){
    myservo.write(0);
    digitalWrite(pinLed, HIGH);
  }

  if (digitalRead(pulsadorCientochentaGrados) == LOW){
    myservo.write(180);
    digitalWrite(pinLed, LOW);
  }
}
