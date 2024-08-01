/*
COMPONENTS REQUIRE:
  Arduino uno or any arduino version
  DHT11 or DHT22 or DHT21
  LCD_I2C any size 
  few Jumper wires
  RGB LED
  Three 330 ohms resistor
LIBRARY REQUIRE:
  LCD_I2C Library
  If you have LCD Without I2C intall LCD library
  DHT sensor Library
*/

//Including LCD_I2C header file
#include <LiquidCrystal_I2C.h>
//Include DHT header file
#include <DHT.h>
#include <DHT_U.h>
//Define the dht connected pin with the arduino
#define DHTPIN 3
//Define DHT type like DHT11,DHT22,DHT21....
#define DHTTYPE DHT11
//Initialize DHT
DHT dht(DHTPIN,DHTTYPE);
//These below pins for RGB LED
const int RED=5;
const int GREEN=6;
const int BLUE=7;
//define LCD_I2C address
LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup() {
  // put your setup code here, to run once:
  //LCD display begin
    lcd.begin();
    lcd.backlight();
    //DHT sensor begin
    dht.begin();
    Serial.begin(9600);
    //Initialize RGB LED pins
    pinMode(RED,OUTPUT);
    pinMode(GREEN,OUTPUT);
    pinMode(BLUE,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //delay for reading data every 2 seconds later
  delay(2000);
  //Humidity reading function
  float h=dht.readHumidity();
  //Temperature reading function (default Celsius)
  float t=dht.readTemperature();
  //if failed to gather data return quickly and try again
  if(isnan(h) || isnan(t))
  {
    Serial.print("Failed to gather details");
    return ;
  }
  //Printing on serial monitor, press ctrl+Shift+m to open serial monitor
  Serial.print("Humidity : ");
  Serial.print(h);
  Serial.print("%");
  Serial.print(" Temperature : ");
  Serial.print(t);
  Serial.println("c");
  //Assign position of Humidity and Temperature
  lcd.setCursor(0,0);
  lcd.print("Humidity:");
  lcd.setCursor(9,0);
  lcd.print(h);
  lcd.setCursor(15,0);
  lcd.print("%");
  lcd.setCursor(0,1);
  lcd.print("Temp:");
  lcd.setCursor(6,1);
  lcd.print(t);
  lcd.setCursor(11,1);
  lcd.print("%");
  //statement to Turn on RGB LED based on Humidity change
  if(h>=49)
  {
    digitalWrite(RED,HIGH);
    digitalWrite(GREEN,LOW);
    digitalWrite(BLUE,LOW);
    //delay(100);
  }
  else if(h>45 and h<=48)
  {
    digitalWrite(GREEN,HIGH);
    digitalWrite(RED,LOW);
    digitalWrite(BLUE,LOW);
    //delay(100);
  }
  else if(h>42 and h<=44)
  {
    digitalWrite(BLUE,HIGH);
    digitalWrite(GREEN,LOW);
    digitalWrite(RED,LOW);
    //delay(100);
  }
  else
  {
    digitalWrite(RED,LOW);
    digitalWrite(GREEN,LOW);
    digitalWrite(BLUE,LOW);
    delay(1000);
  }

}
