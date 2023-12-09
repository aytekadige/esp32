#include <LiquidCrystal_I2C.h>
#include <Wire.h> 

LiquidCrystal_I2C lcd(0x27, 16, 2);
// test

//ikinci test
const int leftButton = 1;
const int rightButton = 2;
const int upButton = 41;
const int downButton = 40;
const int selectButton = 39;
const int backButton = 38;

void setup() {
  Wire.begin(10, 8);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(1, 0);
  lcd.print("Button Project");
  lcd.setCursor(2, 1);
  lcd.print("ESP32-S3 I2C");

  delay(2000);
  lcd.clear();
  
  pinMode(leftButton, INPUT_PULLUP);
  pinMode(rightButton, INPUT_PULLUP);
  pinMode(upButton, INPUT_PULLUP);
  pinMode(downButton, INPUT_PULLUP);
  pinMode(selectButton, INPUT_PULLUP);
  pinMode(backButton, INPUT_PULLUP);
}

void loop() {
  int leftState = digitalRead(leftButton);
  int rightState = digitalRead(rightButton);
  int upState = digitalRead(upButton);
  int downState = digitalRead(downButton);
  int selectState = digitalRead(selectButton);
  int backState = digitalRead(backButton);

  lcd.clear();
  
  if (leftState == LOW) {
    lcd.print("Left Button");
  } else if (rightState == LOW) {
    lcd.print("Right Button");
  } else if (upState == LOW) {
    lcd.print("Up Button");
  } else if (downState == LOW) {
    lcd.print("Down Button");
  } else if (selectState == LOW) {
    lcd.print("Select Button");
  } else if (backState == LOW) {
    lcd.print("Back Button");
  } else {
    lcd.print("   No Button");
    lcd.setCursor(0, 1);
    lcd.print("    Pressed");
  }

  delay(100);
}