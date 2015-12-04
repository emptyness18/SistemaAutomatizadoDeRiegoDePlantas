/*
  Proyecto para feria cientifica de Sion
  Integrantes: Byron Cordero, Wmmanuel Cortez, Jorge Aguilar
*/
#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>
#include <Adafruit_MotorShield.h>
#include <Servo.h>

#define LIMITE_SECO 260
#define LIMITE_BIEN 200

#define I2C_ADDR 0x27
#define BACKLIGHT_PIN 3
#define En_pin 2
#define Rw_pin 1
#define Rs_pin 0
#define D4_pin 4
#define D5_pin 5
#define D6_pin 6
#define D7_pin 7

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 

Adafruit_DCMotor *myMotor = AFMS.getMotor(1);

LiquidCrystal_I2C lcd(I2C_ADDR, En_pin, Rw_pin, Rs_pin, D4_pin, D5_pin, D6_pin, D7_pin);

int pinSensorHumedad = A0;
int lecturaDeHumedad = 0;
int retrasoDeCiclo = 30000;
Servo servo;

void setup() {
  Serial.begin(9600); 
  
  lcd.begin(16, 2);
  lcd.setBacklightPin(BACKLIGHT_PIN, POSITIVE);
  lcd.setBacklight(HIGH);
  lcd.home();
 
  servo.attach(9);

  servo.write(150);
  
  lcd.print("Hola");
  
  AFMS.begin();
  myMotor->setSpeed(255);

  delay(10000);
 
}
void irrigar() {
  Serial.print("irrigando");
  myMotor->run(FORWARD); 
  int position;

  for(position = 125; position < 160; position += 2)
  {
    servo.write(position);  // Move to next position
    delay(50);               // Short pause to allow it to move
  }
 
  myMotor->run(RELEASE);
 
  delay(2000);
}

void loop() {
  lecturaDeHumedad = analogRead(pinSensorHumedad);
  Serial.print("lectura ");
  Serial.println(lecturaDeHumedad);
  lcd.clear();
  lcd.setCursor (0, 1);
  lcd.print("Lectura");
  lcd.setCursor (8, 1);
  lcd.print(lecturaDeHumedad);  
  
  
  if(lecturaDeHumedad>=LIMITE_SECO) 
  {
      Serial.println("esta seco");
      lcd.setCursor(0, 0);
      lcd.print("Esta seco");
      irrigar();
      
  }
  else if(lecturaDeHumedad>=LIMITE_BIEN)
  {
      Serial.println("esta bien");
      lcd.setCursor(0, 0);
      lcd.print("Esta bien");
  }
  else
  {
      Serial.println("sobre Hidratado");
      lcd.setCursor(0, 0);
      lcd.print("Sobre hidratado");
  }
  
  delay(retrasoDeCiclo);

}







