#include <DHT.h>
#define Type DHT11 

#include <LiquidCrystal.h>

/**************************************************
Author:         Fawaaz Kamali Siddiqui
Date:           10 April 2023
Description:    This device is called the portable temperature
                and humidity calculator. It contains an LCD to
                output temperature in Celsius and humidity using
                the DHT11 temperature and humidity sensor. A 
                powerbank is used to supply the Arduino Nano.
---------------------------------------------------
Connections:    sensor pin: 2
                rs:         12
                e:          11
                d4:         4
                d5:         5
                d6:         6
                d7:         7
**************************************************/

// variables 
int sensorPin = 2;
int rs = 12;
int e = 11;
int d4 = 4;
int d5 = 5;
int d6 = 6;
int d7 = 7;
float humidity;
float tempCelsius;

// instantiation
DHT HT(sensorPin, Type);
LiquidCrystal lcd(rs, e, d4, d5, d6, d7);

// custom symbol for display
byte degree[8] = { 
  B00100, 
  B01010, 
  B01010, 
  B00100, 
  B00000, 
  B00000, 
  B00000, 
  B00000
} ;

void setup() {
  
  lcd.begin(16, 2);
  lcd.createChar(7, degree);
  HT.begin();
  Serial.begin(9600);

}

void loop() {
  
  // read temp and humidity 
  humidity = HT.readHumidity();
  tempCelsius = HT.readTemperature();

  // display temp and humidity
  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(tempCelsius);
  lcd.write(byte(7));
  lcd.print("C");
  
  lcd.setCursor(0,1);
  lcd.print("Humidity: ");
  lcd.print(humidity);
  lcd.setCursor(15, 1);
  lcd.print("%");
  
  delay(500);

}
