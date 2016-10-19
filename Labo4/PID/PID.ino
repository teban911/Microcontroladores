#include <PID_v1.h> 

//Variables
double Setpoint, Input, Output;
unsigned long DataRead;
int Analog_Input;
String Datos;

//Se inicializa el PID: PID(&Input, &Output, &Setpoint, Kp, Ki, Kd, Direction)
PID myPID(&Input, &Output, &Setpoint,5,0,0, REVERSE);

void setup() {
  Serial.begin(9600);
  Input = analogRead(0);
  Setpoint = 1;
  //Se enciende el PID
  myPID.SetMode(AUTOMATIC);
}

void loop() {
  /*if (Serial.available()){
    Datos = Serial.read(); //Se lee el valor ingresado cada vez que haya una interrupcion por el puerto serial
    Setpoint = Datos.toFloat();
    //Setpoint = DataRead;
  } */
  Analog_Input = analogRead(0);
  Input = (double)Analog_Input/1024;
  Input = Input*5;
  Input = Input-0.5;
  Input = Input *100;
  //Serial.println(DataRead);
  myPID.Compute();
  analogWrite(3,Output);
}

