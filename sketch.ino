#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // Zdefiniowanie adresu I2C wyświetlacza

// Definicja znaku specjalnego "ś"
byte customChar[8] = {
  B00010,
  B00100,
  B01110,
  B10000,
  B01110,
  B00001,
  B11110,
  B00000
};

void setup() {
  lcd.init(); // Inicjalizacja LCD
  lcd.backlight(); // Włączenie podświetlenia
  lcd.createChar(0, customChar); // Tworzenie znaku specjalnego "ś"

  // Wyświetlenie tekstu "Adrian Leśniak"
  lcd.clear(); // Czyszczenie wyświetlacza
  lcd.setCursor(0,0); // Ustawienie kursora na początku pierwszej linii
  lcd.print("Adrian Le"); // Wyświetlenie pierwszej części tekstu
  lcd.write(byte(0)); // Wstawienie znaku specjalnego "ś"
  lcd.print("niak"); // Wyświetlenie reszty tekstu
}

void loop() {
  // Pętla główna nie jest potrzebna w tym przypadku
}