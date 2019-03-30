#include "Arduino.h"
#include "LiquidCrystal.h"
#include "PinLayout.h"
#include "LCD.h"

// The body of the LCD library

LCD::LCD() : lcd(lcdReset, lcdEnable, lcdDataLine4, lcdDataLine5, lcdDataLine6, lcdDataLine7)
{
  PinLayout pinLayout;
  pinLayout.setup();
  lcd.begin(20, 4);
 // lcd.noAutoscroll();
  homeMenuCurrentOption = 1;
}

void LCD::printWelcomeScreen() {
  lcd.clear();
  lcd.setCursor(4, 0);
  // TBD every loop put in another line
  lcd.print("Drink anyone?");
  lcd.setCursor(5, 1);
  lcd.print("<< START >>");
  lcd.setCursor(0, 3);
  lcd.print("Use App / Hit Select");
}

void LCD::printHomeScreen() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("   Manual Mode!");
  lcd.setCursor(0, 1);
  lcd.print("   Get a drink");
  lcd.setCursor(0, 2);
  lcd.print("   Play Plinko Game");
  homeMenuCurrentOption = 1;
  updateHomeSelection();
}

void LCD::moveHomeSelection(char direction) {
  if (direction == 'd') {
    if (homeMenuCurrentOption == 2) {
      homeMenuCurrentOption = 1;
    } else {
      homeMenuCurrentOption++;
    }
  } else if (direction == 'u') {
    if (homeMenuCurrentOption == 1) {
      homeMenuCurrentOption = 2;
    } else {
      homeMenuCurrentOption--;
    }
  }
  updateHomeSelection();
}

void LCD::updateHomeSelection() {
  lcd.setCursor(0, 1);
  lcd.print(" ");
  lcd.setCursor(0, 2);
  lcd.print(" ");
  lcd.setCursor(0, 3);
  lcd.print(" ");
  lcd.setCursor(0, homeMenuCurrentOption);
  lcd.print(">");
}

int	LCD::getHomeSelection()	{
	return homeMenuCurrentOption;
}

void LCD::printBluetoothScreen() {
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("Hijacked by Androids");
  lcd.setCursor(2, 2);
  lcd.print("<< USING APP >>");
}

void LCD::printGameScreen() {  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" Welcome to Plinko ");
  lcd.setCursor(0, 1);
  lcd.print("   Please Insert Coin   "); 
}

void LCD::printGameOutcomeScreen(int result) {
  switch(result) {
    case 0:  printGameOutcomeWin(100, 0); //  A = 100 and B = 0
        break;
    case 1:  printGameOutcomeWin(25, 75); //  A = 25 and B = 75
        break;
    case 2:  printGameOutcomeLose();      //  A = 0 and B = 0
        break;
    case 3:  printGameOutcomeWin(50, 50); //  A = 50 and B = 50
        break;
    case 4:  printGameOutcomeLose();      //  A = 0 and B = 0
        break;
    case 5:  printGameOutcomeWin(75, 25); //  A = 75 and B = 25
        break;
    case 6:  printGameOutcomeWin(0, 100); //  A = 0 and B = 100
        break;
  }
}

void LCD::printGameOutcomeWin( int A, int B) {
  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("WINNER/GAGNANT");
  lcd.setCursor(3, 1);
  lcd.print("%");
  lcd.print(A);
  lcd.print("  of A");
  lcd.setCursor(3, 2);
  lcd.print("%");
  lcd.print(B);
  lcd.print(" of B");
}

void LCD::printGameOutcomeLose() {
  lcd.clear();
  lcd.setCursor(7, 1);
  lcd.print("You Lose!");
  lcd.setCursor(7, 2);
  lcd.print("Try Again!");
}

void LCD::printTimeoutPlaceholder () {
  lcd.setCursor(9,3);
  lcd.print("TIMEOUT= 60");
}

void LCD::updateTimeout(int counter) {
  lcd.setCursor(18,3);
  if (counter > 9) {
    lcd.print(counter);
  }
  else {
    lcd.print(" ");
    lcd.print(counter);
  }
}

void LCD::printTimeoutOccurred() {
  lcd.clear();
  lcd.setCursor(7,1);
  lcd.print("TIMEOUT");
}