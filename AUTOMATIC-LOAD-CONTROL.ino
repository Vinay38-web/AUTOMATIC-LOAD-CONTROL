#include <LiquidCrystal.h>
const int rs = 7, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
const int analogInPin = A0;
int sensorValue = 0;
int voltage = 0;
int small_load=9;
int large_load=8;
int a=1;
int b=1;
int c=1;
int d=1;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
void setup() 
{
 pinMode(small_load,OUTPUT);
 pinMode(large_load,OUTPUT);
 digitalWrite(small_load,HIGH);
 digitalWrite(large_load,HIGH);
 lcd.begin(16, 2);
 Serial.begin(9600);
  //lcd.setCursor(0, 0);
 lcd.print(" Voltage - ");
 lcd.setCursor(0,1);
 lcd.print(" HL-off SL-off ");
}
void loop() 
{
  sensorValue = analogRead(analogInPin);
  voltage = map(sensorValue, 0, 1023, 0, 255);
  lcd.setCursor(11,0);
  lcd.print(voltage);
  lcd.print("   ");
  if(voltage>=180 && voltage<=235 && b==1)
  {
    digitalWrite(small_load,HIGH);
    delay(100);
    digitalWrite(large_load,LOW);
    lcd.setCursor(0,1);
    lcd.print(" HL-off SL-off  ");
    lcd.setCursor(4,1);
    lcd.print("ON ");
     lcd.setCursor(11,1);
    lcd.print("OFF");
    b=0;
    a=1;
    c=1;
    d=1;
  }
  else if(voltage>=110 && voltage<180 && a==1)
  {
    digitalWrite(large_load,HIGH);
    delay(100);
    digitalWrite(small_load,LOW);
    lcd.setCursor(0,1);
    lcd.print(" HL-off SL-off  ");
    lcd.setCursor(4,1);
    lcd.print("OFF");
    lcd.setCursor(11,1);
    lcd.print("ON ");
    a=0;
    b=1;
    c=1;
    d=1;
  }
  else if(voltage<110 && c==1)
  {
    digitalWrite(large_load,HIGH);
    delay(100);
    digitalWrite(small_load,HIGH);
    lcd.setCursor(0,1);
    lcd.print(" Under Voltage ");
    a=1;
    b=1;
    c=0;
    d=1;
  }
  else if(voltage>235 && d==1)
  {
    digitalWrite(large_load,HIGH);
    delay(100);
    digitalWrite(small_load,HIGH);
    lcd.setCursor(0,1);
    lcd.print("  Over Voltage  ");
    a=1;
    b=1;
    c=1;
    d=0;
  }
}
