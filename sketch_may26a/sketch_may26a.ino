#include <Wire.h> // Include Wire library for I2C
#include <LiquidCrystal_I2C.h> // Include the LiquidCrystal I2C library for LCD
#include <Keypad.h> // Include the Keypad library

const byte ROWS = 4; // Define the number of rows on the keypad
const byte COLS = 4; // Define the number of columns on the keypad

// Define the keymap for the keypad
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

// Define the pins for the rows and columns of the keypad
byte rowPins[ROWS] = { 2, 3, 4, 5 }; // Connect keypad ROW0, ROW1, ROW2, and ROW3 to these Arduino pins
byte colPins[COLS] = { 6, 7, 8, 9 }; // Connect keypad COL0, COL1, COL2, and COL3 to these Arduino pins

// Create a Keypad object
Keypad kpd = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// Initialize the LCD with I2C address 0x27 (you may need to adjust the address)
LiquidCrystal_I2C lcd(0x27, 16, 2); // Change the address to match your I2C module

// Declare variables for the numbers and operation
long Num1, Num2, Number;
char key, action;
boolean result = false;

void setup() {
  lcd.begin(); // Initialize the LCD
  lcd.backlight(); // Turn on the backlight
  lcd.setCursor(0, 0);
  lcd.print("CSE-331 PROJECT"); // Display an intro message
  lcd.setCursor(0, 1); // Set the cursor to column 0, line 1
  lcd.print("Calculator"); // Display an intro message
  delay(2000); // Wait for 2 seconds
  lcd.clear(); // Clear the LCD
}

void loop() {
  key = kpd.getKey(); // Get the key pressed on the keypad

  if (key != NO_KEY) // If a key is pressed
    DetectButtons(); // Detect the button pressed

  if (result == true) // If the result is calculated
    CalculateResult(); // Calculate the result

  DisplayResult(); // Display the result
}

void DetectButtons() {
  lcd.clear(); // Clear the LCD

  // Handle each key press
  if (key == '*') {
    Serial.println("Button Cancel"); // Print to Serial Monitor
    Number = Num1 = Num2 = 0; // Reset numbers
    result = false; // Reset result flag
  }

  // Handle number buttons
  if (key >= '0' && key <= '9') {
    Serial.print("Button ");
    Serial.println(key);
    if (Number == 0)
      Number = key - '0';
    else
      Number = (Number * 10) + (key - '0'); // Append digit
  }

  // Handle operation buttons
  if (key == 'A' || key == 'B' || key == 'C' || key == 'D') {
    Num1 = Number; // Store the first number
    Number = 0; // Reset the number
    if (key == 'A') {
      Serial.println("Addition");
      action = '+'; // Set addition operation
    }
    if (key == 'B') {
      Serial.println("Subtraction");
      action = '-'; // Set subtraction operation
    }
    if (key == 'C') {
      Serial.println("Multiplication");
      action = '*'; // Set multiplication operation
    }
    if (key == 'D') {
      Serial.println("Division");
      action = '/'; // Set division operation
    }
    delay(100);
  }

  if (key == '#') {
    Serial.println("Button Equal");
    Num2 = Number; // Store the second number
    result = true; // Set result flag
  }
}

void CalculateResult() {
  // Perform the calculation based on the action
  if (action == '+')
    Number = Num1 + Num2;
  if (action == '-')
    Number = Num1 - Num2;
  if (action == '*')
    Number = Num1 * Num2;
  if (action == '/')
    Number = Num1 / Num2;
}

void DisplayResult() {
  lcd.setCursor(0, 0); // Set the cursor to column 0, line 0
  lcd.print(Num1); lcd.print(action); lcd.print(Num2); // Display the expression
  
  if (result == true) {
    lcd.print(" ="); lcd.print(Number); // Display the result
  }
  
  lcd.setCursor(0, 1); // Set the cursor to column 0, line 1
  lcd.print(Number); // Display the result
}
