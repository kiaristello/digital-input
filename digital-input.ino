#include <Servo.h>
Servo myservo;


int pulsadorCeroGrados = 7; 
int pulsadorCientochentaGrados = 6;
int pinServo = 2;

void setup() {
  // Entradas digitales
  pinMode(pulsadorCeroGrados, INPUT_PULLDOWN);
  pinMode(pulsadorCientochentaGrados, INPUT_PULLDOWN);

  // Configurando Servo
  myservo.attach(pinServo);
  myservo.write(90);// move servos to center position -> 90°
}

void loop() {
  // put your main code here, to run repeatedly:

}
