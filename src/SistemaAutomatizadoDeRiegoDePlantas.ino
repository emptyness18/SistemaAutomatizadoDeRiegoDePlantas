/*
  Proyecto para feria cientifica de Sion
  Integrantes: Byron Cordero
*/

#define LIMITE_SECO 600
#define LIMITE_BIEN 300

int pinSensorHumedad = A0;
int lecturaDeHumedad = 0;
int retrasoDeCiclo = 5000;

void setup() {
  Serial.begin(9600); 
}

void loop() {
  lecturaDeHumedad = analogRead(pinSensorHumedad);
  Serial.print("lectura");
  Serial.println(lecturaDeHumedad);
  
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
