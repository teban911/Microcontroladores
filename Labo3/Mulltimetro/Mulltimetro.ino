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
// preMillis y rebote son variables que se utilizan para controlar el rebote del botob
unsigned long preMillis = 0;
long rebote = 400;

//Se inicializan las variables
void setup() {
  Serial.begin(9600);
  pinMode(button, INPUT);
  pinMode(punta, INPUT);
  // Se inicializa el estado del boton como apagado
  buttonState = LOW;
}

void loop() {
  /* Se lee el boton analogico, si su estado anterior era low procede a encender y realizar la toma de dator
     Si el estado anterior era HIGH procede procede a apagarlo y detener la toma de datos
  */
  if (digitalRead(button) == HIGH) {
    // Se guarda el tiempo actual
    unsigned long currentMillis = millis();
    // espera hasta que el tiempo actual menos premillis sea mayor que rebote para ingresar al if
    if ((currentMillis - preMillis) >= rebote) {
      if (buttonState == LOW) {
        buttonState = HIGH;
        // se toma el tiempo de referencia
        t_ref = millis();
      }
      else {
        buttonState = LOW;
      }
    }
  }
  //Este if se toma cuando el estado del boton es encendido encendido
  if (buttonState == HIGH) {
    t_act = millis();
    tiempo = (t_act - t_ref);
    lectura = analogRead(punta);
    // se mapea a un correspondiente valor de 0-500mV
    lectura = map(lectura, 0, 1023, 0, 500);
    // Se divide entre 100 para obtener el voltaje directamente en V
    float voltaje = (lectura / escala);
    Serial.print(tiempo);
    Serial.write("\t");
    Serial.println(voltaje);

  }
  delay(100);
}
