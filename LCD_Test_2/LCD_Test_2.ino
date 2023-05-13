

// include the library code:
#include <LiquidCrystal.h>
int Contrast=80;
// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 13, en = 12, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
      analogWrite(6,Contrast);
      delay(1000);
}

void loop() {
  // set the cursor to (0,0):
//  lcd.display();
  //  delay(500);
  lcd.setCursor(0, 0);
 //   delay(150);
  // print from 0 to 9:
  for (int thisChar = 0; thisChar < 13; thisChar++) {
    lcd.print(thisChar);
    delay(500);
  }

  // set the cursor to (16,1):
  lcd.setCursor(16, 1);
 //   delay(150);
  // set the display to automatically scroll:
  lcd.autoscroll();
 //  delay(150);
  // print from 0 to 9:
  for (int thisChar = 0; thisChar < 13; thisChar++) {
    lcd.print(thisChar);
    delay(500);
  }
  // turn off automatic scrolling
  lcd.noAutoscroll();
  //  delay(1000);

  // clear screen for the next loop:
  lcd.clear();
  //  delay(500);
  //lcd.noDisplay();
    delay(1000);
}
