#include <LiquidCrystal.h>
//Se definen los pines para la pantalla LCD
LiquidCrystal lcd(12, 11, 5, 4, 8, 6);
//Definicion de variables
volatile byte Rev;    //Variable para almacenar las revoluciones
unsigned long int rpm, maxRPM;  //Se definen las variables de revoluciones por min y el max de revoluciones
unsigned long time;  //Se define el tiempo que tarda en dar una revolucion
int LedPin = 13;
int led = 0;
int CurrRPM, PrevRPM;
int flag = 0;
long prevtime = 0;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2); //Se inicializa la pantalla, 16 columnas 2 filas
  attachInterrupt(0,RPMcount, RISING);  //Se define una interrupcion de alta prioridad por el flanco creciente de la sennal proveniente del fototransistor.
  // Se inicializan las variables
  Rev = 0;
  rpm = 0;
  time = 0;
  pinMode(LedPin,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(10,OUTPUT);
  digitalWrite(3,HIGH);    // Vcc para el sensor
  digitalWrite(10,LOW);      //Gnd
  lcd.print("TACOMETRO");
  lcd.setCursor(0,1);
  lcd.print("Lab MicroCtr"); 
  delay(2000);
  lcd.clear();
}

void loop() {
  long currentMillis = millis();   //Se otiene el tiempo de actual como referencia
  long tiempoInactivo = currentMillis - prevtime;

  if(Rev >= 5){     //Se  actualiza cada cinco lecturas
    if(flag == 0){
      lcd.clear();
      lcd.print("Lectura del sensor");
      flag = 1;   // Se pone la bandera en 1 para no volver a entrar al if
    } 
    rpm = 30*1000/(millis() - time)*Rev;  //Se realiza el calculo de las revoluciones por minuto
    
    //Se actualiza el max de rev por minuto
    if(rpm > maxRPM)
      maxRPM = rpm;
      time = millis();
      Rev = 0;          //Se refrescan los valores de tiempo y Rev.
      int digits = rpm;
      while (digits != 0){
        digits = digits/10;
        CurrRPM++;
      }

      if (CurrRPM != PrevRPM){
        lcd.clear();
        PrevRPM = CurrRPM;
        flag = 0;
        lcd.print("Lectura del sensor"); 
        }
        
      lcd.setCursor(0,1);   //Se mueve el cursos a la segunda fila
      lcd.print(rpm,DEC);   //Se imprimen las rpm en decimal
      lcd.setCursor(6,1);  //Se desplaza el cursos 6 unidades en el eje x
      lcd.print("RPM");    //Se imprime el mensaje RPM
      delay(500);          //Se da un tiempo de espera de medio 
      prevtime = currentMillis;   //Se recetea el tiempo
    }     
    
  if(tiempoInactivo > 5000){ //Si despues de 5 segundos no hay una lectura se despliega el valor de maxRPM 
    if(flag == 1){
      lcd.clear();
      flag = 0;  
    }

    lcd.clear();
    lcd.print("MAX RPM");
    lcd.setCursor(0,1);
    lcd.print(maxRPM,DEC);
    lcd.print("   RPM");
    delay(2000);
    lcd.clear();
    lcd.print("Tiempo de espera");
    lcd.setCursor(0,1);
    lcd.print("Listo para sensar");
    delay(2000);
    prevtime = currentMillis; 
  } 
}

void RPMcount(){
  Rev++;
  if(led == LOW){
    led = HIGH;
  }
  else{
    led = LOW;
  }
  digitalWrite(LedPin, led);
} 

