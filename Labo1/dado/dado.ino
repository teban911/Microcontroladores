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
unsigned long preMillis = 0;
long rebote = 400;


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
    unsigned long currentMillis = millis();
    if((currentMillis - preMillis) >= rebote){ 
      preMillis = currentMillis;
      dado[0]= random(0,256);
      dado[1]= random(0,256);
      dado[2]= random(0,256);
      dado[3]= random(0,256);
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
  lastButtonState = buttonState;
} 
