#include <Servo.h>
Servo myservo;

int pulsadorCeroGrados = 7; 
int pulsadorCientochentaGrados = 6;
int pinServo = 2;
int pinLed = 4;
boolean encendido = false;

void setup() {
  Serial.begin(9600);
  Serial.println("Iniciando programa");
  // Entradas digitales
  pinMode(pulsadorCeroGrados, INPUT_PULLUP);
  pinMode(pulsadorCientochentaGrados, INPUT_PULLUP);
  pinMode(pinLed, OUTPUT);


  // Configurando Servo
  myservo.attach(pinServo);
  myservo.write(90);// move servos to center position -> 90°
}

void loop() {
  if (encendido == "false"){
    Serial.println("Introducir palabra secreta");
    while (Serial.available() == 0);
    String comando = Serial.readString();
    if (comando == 'encender'){
      encendido = true;
    }else{
      Serial.println("NO ERES TU 👀");
    }
  } else {
    // Configurando ángulos y leds
    if (digitalRead(pulsadorCeroGrados) == LOW){
      Serial.println("Mi Servo se esta moviendo a 0°");
      myservo.write(0);
      digitalWrite(pinLed, HIGH);
    }

    if (digitalRead(pulsadorCientochentaGrados) == LOW){
      Serial.println("Mi Servo se esta moviendo a 180°");
      myservo.write(180);
      digitalWrite(pinLed, LOW);
    }
  }

}
