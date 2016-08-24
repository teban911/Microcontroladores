/*
Esteban Vargas Arrieta  A96486          
Ignacio Picado Vargas A94781 
*/
//Se incluye la libreraia TimerOne que nos permitira trabajar con timers
#include <TimerOne.h>

// Variables
// Variable que almacena el estado del boton
int buttonState = 0;
//variable que almacena el estado del boton
int lastButonState = 0;
// Variables de tiempo en segundos
long diez = 10000;
long tres = 3000;
long dos = 2000;
unsigned long preMillis = 0;
unsigned long currentMillis;


// Variables para los leds de los semaforos
int boton = 13;
int verdeC = 12;
int amarilloC = 11;
int rojoC = 10;
int verdeP = 9;
int rojoP = 8;
void setup() {
  //Se definen los I/O
  pinMode(verdeC,OUTPUT);
  pinMode(amarilloC,OUTPUT);
  pinMode(rojoC,OUTPUT);
  pinMode(verdeP,OUTPUT);
  pinMode(rojoP,OUTPUT);
  pinMode(boton,INPUT);
}

void loop() {
  // Se setea el estado inicial del semaforo en caso de que nadie haya presionado el boton
  digitalWrite(verdeC,HIGH);
  digitalWrite(rojoP,HIGH);
  digitalWrite(amarilloC,LOW);
  digitalWrite(rojoC,LOW);
  digitalWrite(verdeP,LOW);
  //Se lee si se ha presionado el boton del semaforo
  buttonState = digitalRead(boton);
  //Si el boton se presiona se ejecuta el siguiente codigo
  if(buttonState != lastButtonState) {
    currentMillis = millis();
    //Se cuentan los primeros diez segundos antes de entrar a parpadear
    while(currentMillis - preMillis > diez){
      digitalWrite(verdeC,HIGH);
      digitalWrite(rojoP,HIGH);
      preMillis = currentMillis;
    }
    //Actualizo los timers para el siguiente lazo
    preMillis = 0;
    currentMillis = millis()
    while(currentMillis - preMillis > tres){
      digitalWrite(verdeC,LOW)
    }
  }

}
