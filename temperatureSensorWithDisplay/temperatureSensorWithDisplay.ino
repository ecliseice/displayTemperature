
#include <Wire.h>
#include <LCD_1602_RUS.h>

#include "DHT.h"


LCD_1602_RUS lcd(0x27, 16, 2);
int DS1307_I2C_ADDRESS = 0x68;

#define DHTPIN 2
DHT dht(DHTPIN, DHT22);

void setup() {
  Wire.begin();
  Serial.begin(9600);
  while (!Serial) ;
  lcd.init();
  lcd.setBacklight(true);
  dht.begin();
}

void loop() {

  delay(1000);
  float humidity = dht.readHumidity(); //Измеряем влажность
  float temp = dht.readTemperature(); //Измеряем температуру
  if (isnan(humidity) || isnan(temp)) {  
    Serial.println("Ошибка считывания");
    return;
  }
     lcd.setCursor(1, 0);
     lcd.print("Темп. - ");
     lcd.print(temp);
     lcd.setCursor(1, 1);
     lcd.print("Влаж. - ");
     lcd.print(humidity);
}
