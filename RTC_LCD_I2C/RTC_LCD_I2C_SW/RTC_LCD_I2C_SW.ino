#include <Wire.h>
#include <RTClib.h>
#include <LiquidCrystal_I2C.h>

RTC_Millis rtc;
LiquidCrystal_I2C lcd(0x3F, 20, 4); // LCD adresi ve boyutu

const int leftButton = 27;
const int rightButton = 14;
const int upButton = 16;
const int downButton = 2;
const int selectButton = 12;
const int backButton = 13;


void setup() {
  Wire.begin();
  
  lcd.begin();
  lcd.backlight();
  rtc.begin(DateTime(F(__DATE__), F(__TIME__)));
}

void loop() {
  DateTime now = rtc.now();
  
  lcd.setCursor(1, 0);
  lcd.print("Date: ");
  lcd.print(now.day(), DEC);
  lcd.print('/');
  lcd.print(now.month(), DEC);
  lcd.print('/');
  lcd.print(now.year(), DEC);
  
  lcd.setCursor(1, 1);
  lcd.print("Time: ");
  printDigits(now.hour());
  lcd.print(':');
  printDigits(now.minute());
  lcd.print(':');
  printDigits(now.second());
  
  delay(1000); // Her saniye güncelleme yapmak için bir saniye bekle
}

void printDigits(int digits) {
  if (digits < 10) {
    lcd.print('0');
  }
  lcd.print(digits);
}