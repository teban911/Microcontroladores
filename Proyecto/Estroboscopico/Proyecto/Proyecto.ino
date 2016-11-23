#include <LiquidCrystal.h>
//Se definen los pines para la pantalla LCD
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int digPin1 = 13; //       led flash
//int digPin2 = 9; //       led flash
//int digPin3 = 8; //       led flash
int pulsadorsuma=0;              //almacena el estado del botón de suma
int pulsadordiv=0;
int pulsadormult=0;
int pulsadorresta=0;              //almacena el estado del botón de resta
int lastpulsadorsuma=0;
int lastpulsadorresta=0;
int lastpulsadormult=0;
int lastpulsadordiv=0;
unsigned long preMillis = 0;
long rebote = 400;



int suma=0;        // me dice si tengo que restar
int resta =0;     // me dice si tengo que restar
float fpm = 500;      //frecuencia inicial de flasheo
float mciclo;
float c1;

void setup() 
{
   lcd.begin(16, 2); //Se inicializa la pantalla, 16 columnas 2 filas
   pinMode(digPin1, OUTPUT);     // pin en modo salida
//   pinMode(digPin2, OUTPUT);     // pin en modo salida
//   pinMode(digPin3, OUTPUT);     // pin en modo salida
   pinMode(10, INPUT);           //boton de multiplicacion
   pinMode(9, INPUT);           //boton de division
   pinMode(8, INPUT);         //boton de suma
   pinMode(7, INPUT);          // boton de resta
   Serial.begin(9600);
  lcd.print("TACOMETRO");
  lcd.setCursor(0,1);
  lcd.print("Proy MicroCtr"); 
  delay(2000);
  lcd.clear();
  lcd.print("Ignacio Picado");
  lcd.setCursor(0,1);
  lcd.print("Esteban Vargas"); 
  delay(2000);
  lcd.clear();
}

void loop() {
pulsadorsuma = digitalRead(8); //lee si el botón de suma esta siendo pulsado
if(pulsadorsuma != lastpulsadorsuma) {
    unsigned long currentMillis = millis();
    
   if((currentMillis - preMillis) >= rebote){ 
      preMillis = currentMillis;
  if(pulsadorsuma==HIGH){ //si el boton es pulsado y antes no lo estaba

    fpm = fpm+1;
      }
    }
  }
pulsadorresta = digitalRead(7); //lee si el botón de resta esta siendo pulsado
  if(pulsadorresta != lastpulsadorresta) {
    unsigned long currentMillis = millis();
    
   if((currentMillis - preMillis) >= rebote){ 
      preMillis = currentMillis;
  if(pulsadorresta==HIGH){
    fpm = fpm-1;
  
      }
    }
  }

pulsadormult = digitalRead(10); //lee si el botón de multiplicacion esta siendo pulsado
  if(pulsadormult != lastpulsadormult) {
    unsigned long currentMillis = millis();
    
   if((currentMillis - preMillis) >= rebote){ 
      preMillis = currentMillis;
  
  if(pulsadormult==HIGH){
    fpm = fpm+100;
  
      }
    }
  }
  
pulsadordiv = digitalRead(9); //lee si el botón de multiplicacion esta siendo pulsado
  if(pulsadordiv != lastpulsadordiv) {
    unsigned long currentMillis = millis();
    
   if((currentMillis - preMillis) >= rebote){ 
      preMillis = currentMillis;
  if(pulsadordiv==HIGH){
    fpm = fpm-100;
  
      }
    }
  }
  
 mciclo = (30/fpm)*1000;
 //c1=mciclo/3;
   digitalWrite(digPin1, HIGH); // asigna el valor HIGH al pin 
   delay(mciclo);  
   digitalWrite(digPin1, LOW); // asigna el valor LOW al pin
   delay(mciclo);
   
   lcd.clear();
   lcd.print("Frecuencia media"); 
   lcd.setCursor(0,1);   //Se mueve el cursos a la segunda fila
   int frec = (int)fpm;
   lcd.print(frec,DEC);   //Se imprimen las rpm en decimal
   //lcd.setCursor(6,1);  //Se desplaza el cursos 6 unidades en el eje x
   //lcd.print("FPM");    //Se imprime el mensaje RPM
   delay(500);          //Se da un tiempo de espera de medio
     
   
  // digitalWrite(digPin2, HIGH); // asigna el valor HIGH al pin 
  // delay(mciclo); 
  // digitalWrite(digPin2, LOW); // asigna el valor LOW al pin
  // delay(mciclo);  
       
 //  digitalWrite(digPin3, HIGH); // asigna el valor HIGH al pin 
  // delay(mciclo);     
  // digitalWrite(digPin3, LOW); // asigna el valor LOW al pin
  // delay(mciclo);  
   
   
   

   //Serial.print(fpm);
   //Serial.println();  
 
}
