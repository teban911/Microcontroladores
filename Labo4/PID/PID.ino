#include <PID_v1.h> 
#include <LiquidCrystal.h>

//Variables
double Setpoint, Input, Output;
unsigned long DataRead;
int Analog_Input;
int Dato;
//char *lcd_msg[20];


//Se inicializa el PID: PID(&Input, &Output, &Setpoint, Kp, Ki, Kd, Direction)
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
  char buffer[20]= " ";
  
  while (Serial.available() > 0) {
    Dato = Serial.parseInt();
    Setpoint = (double)Dato;
  }
  Analog_Input = analogRead(A0);
  Input = (double)Analog_Input/1024;
  Input = Input*5;
  Input = Input-0.5;
  Input = Input *100;
  myPID.Compute();
  analogWrite(10,Output);
  lcd.print("Set=");
  lcd.print(Dato);
  lcd.print(" ");
  lcd.print("Tmp=");
  lcd.print(Input); 
  delay(1000);
  lcd.clear();
}

