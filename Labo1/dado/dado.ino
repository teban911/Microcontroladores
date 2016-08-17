/*
Esteban Vargas Arrieta  A96486          
Ignacio 
Basado en el ejemplo visto en: http://www.arduino.cc/en/Tutorial/ButtonStateChange
*/

// Variables
int buttonPushCounter = 0; // contador que registra cuantas veces se presiona el contador
int buttonState = 0; // variable que almacena el estado del boton
int lastButtonState = 0; // variable que almacena el estado anterior del boton
int dado[3]; //vecetor que almacena el valor de cada uno de los 4 leds que componen el dado

void setup() {
  // put your setup code here, to run once:
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //se lee al presionar en boton
  buttonState = digitalRead(13);

  //compara el estado del boton y el estado anterior, con base a este calcula el nuevo valor del dado
  if(buttonState != lastButtonState) {
    dado[0]= random(0,2);
    dado[1]= random(0,2);
    dado[2]= random(0,2);
    dado[3]= random(0,2);
    if(dado[0] == 1){
      digitalWrite(9,HIGH);
    }
    else {
      digitalWrite(9,LOW);
    }
    if(dado[1] == 1){
      digitalWrite(10,HIGH);
    }
    else {
      digitalWrite(10,LOW);
    }
    if(dado[2] == 1){
      digitalWrite(11,HIGH);
    }
    else {
      digitalWrite(11,LOW);
    }
    if(dado[3] == 1){
      digitalWrite(12,HIGH);
    }
    else {
      digitalWrite(12,LOW);
    }
    delay(100);
  }
  lastButtonState = buttonState;
}
