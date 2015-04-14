/*
  Proyecto para feria cientifica de Sion
  Integrantes: Byron Cordero
*/
#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

#define LIMITE_SECO 600
#define LIMITE_BIEN 300

#define I2C_ADDR 0x27
#define BACKLIGHT_PIN 3
#define En_pin 2
#define Rw_pin 1
#define Rs_pin 0
#define D4_pin 4
#define D5_pin 5
#define D6_pin 6
#define D7_pin 7

LiquidCrystal_I2C lcd(I2C_ADDR, En_pin, Rw_pin, Rs_pin, D4_pin, D5_pin, D6_pin, D7_pin);

int pinSensorHumedad = A0;
int lecturaDeHumedad = 0;
int retrasoDeCiclo = 5000;

void setup() {
  Serial.begin(9600); 
  
  lcd.begin(16, 2);
  lcd.setBacklightPin(BACKLIGHT_PIN, POSITIVE);
  lcd.setBacklight(HIGH);
  lcd.home();
  
  lcd.print("Hola");
  
  delay(5000);
  
}

void loop() {
  lecturaDeHumedad = analogRead(pinSensorHumedad);
  Serial.print("lectura");
  Serial.println(lecturaDeHumedad);
  lcd.clear();
  lcd.setCursor (0, 1);
  lcd.print("Lectura");
  lcd.setCursor (8, 1);
  lcd.print(lecturaDeHumedad);
  
  
  
  if(lecturaDeHumedad>=LIMITE_SECO) 
  {
      Serial.println("esta seco");
      
  }
  else if(lecturaDeHumedad>=LIMITE_BIEN)
  {
      Serial.println("esta bien");
  }
  else
  {
      Serial.println("sobreHidratado");
  }
  
  delay(retrasoDeCiclo);

}








