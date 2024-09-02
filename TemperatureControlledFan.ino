#include <LiquidCrystal.h> 
#include "DHTStable.h"
#define DHT11_PIN 7

DHTStable dht;

int Contrast=70;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  analogWrite(6, Contrast);
  lcd.begin(16, 2);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(A0, OUTPUT);  
	pinMode(8, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  int chk = dht.read11(DHT11_PIN);
  lcd.setCursor(1,0);
  lcd.print("Temp:");
  lcd.print(dht.getTemperature());
  lcd.print("C");
  lcd.setCursor(1,1);
  lcd.print("Humidity:");
  lcd.print(dht.getHumidity());
  lcd.print("%");
  if(dht.getTemperature() > 20.00){
      digitalWrite(9, HIGH);
      digitalWrite(10, LOW);
  }
  digitalWrite(A0, LOW);  
	delayMicroseconds(2);  
	digitalWrite(A0, HIGH);  
	delayMicroseconds(10);  
	digitalWrite(A0, LOW);  
  float distance = pulseIn(8, HIGH)*(0.0343/2); 
  if(distance < 8.0){
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
  }
}
