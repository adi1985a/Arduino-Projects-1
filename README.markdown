# 📺 Arduino LCD Display – Custom Character Example

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)  
[![Language: C++](https://img.shields.io/badge/Language-C%2B%2B-blue.svg)](https://isocpp.org/)  
[![Platform: Arduino](https://img.shields.io/badge/Platform-Arduino-lightgrey.svg)](https://www.arduino.cc/)

---

## 📋 Description  
This project demonstrates how to create and display a custom character (Polish letter **"ś"**) on a 16x2 I2C LCD using an Arduino. Since standard LCD character sets don’t support some Polish letters, a custom symbol is defined and used to properly display the name **"Adrian Leśniak"**.

The LiquidCrystal_I2C library facilitates communication with the LCD via the I2C protocol, enabling clean text alignment and backlight control.

![Demo GIF](screenshots/1.gif)
---

## 🛠️ Components Required

| Component                | Quantity |
|-------------------------|----------|
| Arduino board (Uno, Nano)| 1        |
| I2C 16x2 LCD display     | 1        |
| Breadboard & jumper wires| As needed|
| USB cable                | 1        |

---

## 🔌 Wiring

| LCD Pin | Arduino Pin    |
|---------|---------------|
| GND     | GND           |
| VCC     | 5V            |
| SDA     | A4 (Uno/Nano) |
| SCL     | A5 (Uno/Nano) |

⚠️ *Pin mapping may vary on other Arduino models (Mega, Leonardo, etc.).*

---

## 💡 Features  
✅ I2C LCD control with LiquidCrystal_I2C library  
✅ Custom character creation for Polish "ś"  
✅ Backlight enabled for better visibility  
✅ Clear and aligned text display  

---

## 💻 Code Overview

```cpp
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // LCD I2C address

// Custom character for Polish "ś"
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
  lcd.init();              // Initialize LCD
  lcd.backlight();         // Turn on backlight
  lcd.createChar(0, customChar); // Define custom char at position 0

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Adrian Le");
  lcd.write(byte(0));      // Print custom "ś"
  lcd.print("niak");
}

void loop() {
  // No loop action needed
}
```

---


## 🖼️ Screenshots  
_Coming soon!_

---

## ⚙️ Installation  
1. Open Arduino IDE.  
2. Navigate to **Tools > Manage Libraries**.  
3. Search for **LiquidCrystal_I2C** and install it (by Frank de Brabander or compatible).  
4. Connect your Arduino board and upload the provided code.  
5. Verify the correct display of the name with the Polish character **"ś"** on the LCD.

---

## 📄 License  
This project is open-source and released under the [MIT License](https://opensource.org/licenses/MIT).  
See the LICENSE file for full details.

---

## 👨‍💻 Author  
**Adrian Leśniak**  
Software Developer

---

💡 Enhance this project by adding more custom characters or dynamic LCD messages!

