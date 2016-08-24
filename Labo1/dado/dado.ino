/*
Esteban Vargas Arrieta  A96486          
Ignacio Picado Vargas A94781 
Basado en el ejemplo visto en: http://www.arduino.cc/en/Tutorial/ButtonStateChange
*/

// Variables
// contador que registra cuantas veces se presiona el contador
int buttonPushCounter = 0;
// variable que almacena el estado del boton
int buttonState = 0; 
// variable que almacena el estado anterior del boton
int lastButtonState = 0;
//vecetor que almacena el valor de cada uno de los 4 leds que componen el dado
int dado[3];
//Variable que almacena la cantidad de milisegundos transcurridos desde que inicia el programa
unsigned long preMillis = 0;
//Rebote indica la cantidad de milisegundos  que debe transcurrir antes de aceptar un nuevo valor como entrada
long rebote = 400;

void setup() {
  // Se definen los I/O
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,INPUT);
}

void loop() {
  //se lee al presionar en boton
  buttonState = digitalRead(13);

  //compara el estado del boton y el estado anterior, con base a este calcula el nuevo valor del dado
  if(buttonState != lastButtonState) {
    unsigned long currentMillis = millis();
    //Realiza la resta y hasta que no se haya cumplido el tiempo de rebote no vuelve a ingresar al if, de modo que se evitan cambios de estado por ruido
    if((currentMillis - preMillis) >= rebote){ 
      preMillis = currentMillis;
      // Se selecciona un numero aleatorio entre 0-256 para cada uno de las casillas del vector dado
      dado[0]= random(0,256);
      dado[1]= random(0,256);
      dado[2]= random(0,256);
      dado[3]= random(0,256);
      // Para cada una de las posiciones del dado selesccionadas aleatoriamente se procede a calcular el modulo 2 de cada una de ellas y dependiendo si es 0 pone la sennal en alto, de lo contrario si es 1 la pone en bajo.
      if(dado[0]%2 == 0){
        digitalWrite(9,HIGH);
      }
      else {
        digitalWrite(9,LOW);
      }
      if(dado[1]%2 == 0){
        digitalWrite(10,HIGH);
      }
      else {
        digitalWrite(10,LOW);
      }
      if(dado[2]%2 == 0){
        digitalWrite(11,HIGH);
      }
      else {
        digitalWrite(11,LOW);
      }
      if(dado[3]%2 == 0){
        digitalWrite(12,HIGH);
      }
      else {
        digitalWrite(12,LOW);
      }
      delay(100);
    }
  }
  // Actualiza el ultimo estado del boton de modo que no se repita el if hasta recibir una nueva pulzacion
  lastButtonState = buttonState;
} 

