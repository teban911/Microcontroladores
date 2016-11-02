#include <PID_v1.h> 
#include <LiquidCrystal.h>

//Variables
double Setpoint, Input, Output;
unsigned long DataRead;
int Analog_Input;
int Dato;

//Se inicializa el PID: PID(&Input, &Output, &Setpoint, Kp, Ki, Kd, Accion de control)
PID myPID(&Input, &Output, &Setpoint,5,2,0, REVERSE);
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup() {
  Serial.begin(9600);
  Input = analogRead(0);
  //Se enciende el PID
  myPID.SetMode(AUTOMATIC);
  lcd.begin(16, 2);
}

void loop() {
  //Si hay un dato en el puerto serial se procede a leerlo
  while (Serial.available() > 0) {
    //Se parsea el dato de string a un entero
    Dato = Serial.parseInt();
    //Se almacena el valor deseado
    Setpoint = (double)Dato;
  }
  //La salida del sensor se lee a traves del puerto analogico A0
  Analog_Input = analogRead(A0);
  //Se hace la conversion del dato leido en mV a grados centigrados.
  Input = (double)Analog_Input/1024;
  Input = Input*5;
  Input = Input-0.5;
  Input = Input *100;
  //Se llama a la funcion PID con los respectivos valores
  myPID.Compute();
  //Se envia la sennal de control a traves del puerto 10, el cual soporta PWM
  analogWrite(10,Output);
  //Se despliegan los valores en la pantalla LCD
  lcd.print("Set=");
  lcd.print(Dato);
  lcd.print(" ");
  lcd.print("Tmp=");
  lcd.print(Input);
  //Este delay es controlar el tiempo de muestreo y de refrescamiento en la pantalla 
  delay(1000);
  lcd.clear();
}

