#include <Servo.h>
Servo myservo;

int pulsador1 = 6; 
int pulsador2 = 7;
int pulsador3 = 8;
int pulsador4 = 9;
int pulsador5 = 10;
int pinServo = 2;
int pinLed = 4;
boolean encendido = false;

void setup() {
  encendido = false;
  Serial.begin(9600);
  Serial.println("Iniciando programa");
  // Entradas digitales
  pinMode(pulsador1, INPUT_PULLUP);
  pinMode(pulsador2, INPUT_PULLUP);
  pinMode(pulsador3, INPUT_PULLUP);
  pinMode(pulsador4, INPUT_PULLUP);
  pinMode(pulsador5, INPUT_PULLUP);

  // Salidas digitales
  pinMode(pinLed, OUTPUT);

  // Configurando Servo
  myservo.attach(pinServo);
  myservo.write(90);// move servos to center position -> 90°
}

void loop() {
  if (encendido == false){
    Serial.println("Introducir palabra secreta");
    while (Serial.available() == 0);
    String comando = Serial.readString();
    if (comando == 'encender'){
      Serial.println("Encendiendo circuito");
      encendido = true;
    }else{
      Serial.println("NO ERES TU 👀");
    }
  } else {
    // Configurando ángulos y leds
      if (digitalRead(pulsador1) == LOW){
        Serial.println("Mi Servo se esta moviendo a 0°");
        myservo.write(0);
        digitalWrite(pinLed, HIGH);
      }

      if (digitalRead(pulsador2) == LOW){
        Serial.println("Mi Servo se esta moviendo a 45°");
        myservo.write(45);
        digitalWrite(pinLed, LOW);
      }
          
      if (digitalRead(pulsador3) == LOW){
        Serial.println("Mi Servo se esta moviendo a 90°");
        myservo.write(90);
        digitalWrite(pinLed, HIGH);
      }

      if (digitalRead(pulsador4) == LOW){
        Serial.println("Mi Servo se esta moviendo a 135°");
        myservo.write(135);
        digitalWrite(pinLed, LOW);
      }    
      
      if (digitalRead(pulsador5) == LOW){
        Serial.println("Mi Servo se esta moviendo a 180°");
        myservo.write(180);
        digitalWrite(pinLed, HIGH);
      }
    }

}
