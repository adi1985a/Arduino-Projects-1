# Arduino LCD Display – Custom Character Example

**A simple Arduino project that demonstrates how to create and display a custom character (Polish letter "ś") on an I2C LCD.**

## Description

This project displays the name **"Adrian Leśniak"** on a 16x2 I2C LCD screen connected to an Arduino board. Since standard LCD character sets do not include certain Polish characters like **"ś"**, the project defines a custom character to render it properly.

The display uses the `LiquidCrystal_I2C` library to communicate via the I2C protocol.

## Components Required

- Arduino board (e.g., Uno, Nano)
- I2C 16x2 LCD display (address: `0x27`)
- Breadboard and jumper wires
- USB cable for programming

## Features

- ✅ I2C LCD control using `LiquidCrystal_I2C`
- ✅ Display of Polish characters using custom symbols
- ✅ Backlight enabled
- ✅ Clean screen and proper text alignment

## Wiring

| LCD Pin | Arduino Pin |
|---------|-------------|
| GND     | GND         |
| VCC     | 5V          |
| SDA     | A4 (Uno/Nano) |
| SCL     | A5 (Uno/Nano) |

> ⚠️ Pin configuration may differ for other Arduino models (e.g., Mega, Leonardo).

## Code Overview

```cpp
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // Set LCD I2C address

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
  lcd.init();            // Initialize LCD
  lcd.backlight();       // Enable backlight
  lcd.createChar(0, customChar); // Define custom char

  lcd.clear();           // Clear screen
  lcd.setCursor(0,0);    
  lcd.print("Adrian Le"); // Print part of the name
  lcd.write(byte(0));     // Insert "ś"
  lcd.print("niak");      // Print the rest
}

void loop() {
  // No action needed in the main loop
}
```

## Installation

1. Install the required library via Arduino IDE:
   - Go to **Tools > Manage Libraries**
   - Search for `LiquidCrystal_I2C` and install it (by Frank de Brabander or compatible)

2. Upload the code to your Arduino board.

## License

This project is open-source and released under the MIT License.

---

> 🛠️ Customize this project further by adding more custom characters or dynamic messages!

