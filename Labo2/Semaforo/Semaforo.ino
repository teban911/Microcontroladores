/*
  Esteban Vargas Arrieta  A96486
  Ignacio Picado Vargas A94781
*/

// Variables
// Variable que almacena el estado del boton
int buttonState = 0;
//variable que almacena el estado del boton
int lastButtonState = 0;
// Variables de tiempo en segundos
long diez = 10000;
long tres = 3000;
long dos = 2000;
long refMillis = 0;
unsigned long currentMillis = 0;
long rebote = 1000;
unsigned long preMillis = 0;


// Variables para los leds de los semaforos
int boton = 13;
int verdeC = 12;
int amarilloC = 11;
int rojoC = 10;
int verdeP = 9;
int rojoP = 8;
const int alarma =5;

void setup() {
  //Se definen los I/O
  pinMode(verdeC, OUTPUT);
  pinMode(amarilloC, OUTPUT);
  pinMode(rojoC, OUTPUT);
  pinMode(verdeP, OUTPUT);
  pinMode(rojoP, OUTPUT);
  pinMode(boton, INPUT);
  pinMode(alarma, OUTPUT);
}

void loop() {
  // Se setea el estado inicial del semaforo en caso de que nadie haya presionado el boton
  digitalWrite(verdeC, HIGH);
  digitalWrite(rojoP, HIGH);
  digitalWrite(amarilloC,LOW);
  digitalWrite(rojoC,LOW);
  digitalWrite(verdeP,LOW);
  
  //Se lee si se ha presionado el boton del semaforo
  buttonState = digitalRead(boton);
  
  //Si el boton se presiona se ejecuta el siguiente codigo
  if (buttonState != lastButtonState) {
    currentMillis = millis();
    
    if ((currentMillis - preMillis) > rebote) {
      preMillis = currentMillis;
      refMillis = millis();
      
      //Se cuentan los primeros diez segundos antes de entrar a parpadear
      while ((millis() - refMillis) < diez) {
        digitalWrite(verdeC, HIGH);
        digitalWrite(rojoP, HIGH);
      }
      
      //Actualizo el tiempo de referencia
      refMillis = millis();
      
      //Se entra al estado de parpadear la luz verde
      while ((millis() - refMillis) < tres) {
        digitalWrite(verdeC, LOW);
        delay(500);
        digitalWrite(verdeC, HIGH);
        delay(500);
      }
      
      //Actualizo el tiempo de referencia
      refMillis = millis();

      //Se entra al estado de encender la luz amarilla y apagar la verde
      while((millis() - refMillis) < tres){
        digitalWrite(verdeC,LOW);
        digitalWrite(amarilloC, HIGH);
      }
      

      
      //Actualizo el tiempo de referencia
      refMillis = millis();
      
      //Entra al estado de encender el la luz roja del semaforo de vehiculos
      digitalWrite(amarilloC, LOW);
      digitalWrite(rojoC, HIGH);
      //Se espera segundo antes de proceder a encender la luz verde del peatonal, esto por seguridad de los peatones ante una infraccion por parte de un vehiculo
      delay(1000);
       
      //Actualizo el tiempo de referencia
      refMillis = millis();
      
      //Entra al estado de encender la luz verde del semaforo
      while((millis() - refMillis) < diez){
        digitalWrite(rojoP, LOW);
        digitalWrite(verdeP, HIGH);
        tone(alarma, 600, 250);
        delay(500);
        noTone(alarma);
        delay(500);
}

       digitalWrite(verdeP, LOW);
       
      //Actualizo el tiempo de referencia
      refMillis = millis();

      //Entra al estado de parpadear la luz roja del paso peatonal
      while((millis() - refMillis) < tres){
        digitalWrite(rojoP, LOW);
        tone(alarma, 600, 250);
        delay(200);
        digitalWrite(rojoP,HIGH);
        noTone(alarma);
        delay(200);

        
      }
      //Entra al estado de poner la luz del semaforo peatonal en rojo y esperar un segundo antes de encender la luz verde del semaforo vehicular
      digitalWrite(rojoP, HIGH);
      delay(1000);
    }
  }
  // Actualiza el ultimo estado del boton de modo que no se repita el if hasta recibir una nueva pulzacion
  lastButtonState = 0;
  buttonState = 0;
}

