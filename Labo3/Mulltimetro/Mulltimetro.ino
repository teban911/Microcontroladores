/*
   Esteban Vargas Arrieta A96486
   Ignasio Picado Vargas  A94781
*/
//Se declara las variables
int punta = A1;
// Variable tiempo que almacena el tiempo al tomar la medida
unsigned long tiempo = 0;
// t_ref y t_act se utilizan para el calculo del tiempo
unsigned long t_ref = 0;
unsigned long t_act = 0;
int button = 13;
int buttonState = LOW;
// Los 100 es para obtener los datos en Voltios (V)
float escala = 100;
float lectura = 0;
unsigned long preMillis = 0;
long rebote = 400;

//Se inicializan las variables
void setup() {
  Serial.begin(9600);
  pinMode(button, INPUT);
  pinMode(punta, INPUT);
  buttonState = LOW;
}

void loop() {
  /* Se lee el boton analogico, si su estado anterior era low procede a encender y realizar la toma de dator
     Si el estado anterior era HIGH procede procede a apagarlo y detener la toma de datos
  */
  if (digitalRead(button) == HIGH) {
    unsigned long currentMillis = millis();
    if ((currentMillis - preMillis) >= rebote) {
      if (buttonState == LOW) {
        buttonState = HIGH;
        t_ref = millis();
      }
      else {
        buttonState = LOW;
      }
    }
  }
  if (buttonState == HIGH) {
    // Se calcula el tiempo al que se toma el dato
    t_act = millis();
    tiempo = (t_act - t_ref);
    lectura = analogRead(punta);
    lectura = map(lectura, 0, 1023, 0, 500);
    float voltaje = (lectura / escala);
    Serial.print(tiempo);
    Serial.write("\t");
    Serial.println(voltaje);
  }
  delay(100);
}
