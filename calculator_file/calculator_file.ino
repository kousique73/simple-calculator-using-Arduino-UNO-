#include <LiquidCrystal.h>  // Include the LiquidCrystal library for LCD
#include <Keypad.h>  // Include the Keypad library

const byte ROWS = 4; // Define the number of rows on the keypad
const byte COLS = 4; // Define the number of columns on the keypad

// Define the keymap for the keypad
char keys[ROWS][COLS] = {
  {'7','8','9','D'},
  {'4','5','6','C'},
  {'1','2','3','B'},
  {'*','0','#','A'}
};

// Define the pins for the rows and columns of the keypad
byte rowPins[ROWS] = { 0, 1, 2, 3 }; // Connect keypad ROW0, ROW1, ROW2, and ROW3 to these Arduino pins
byte colPins[COLS] = { 4, 5, 6, 7 }; // Connect keypad COL0, COL1, COL2, and COL3 to these Arduino pins

// Create a Keypad object
Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

// Define the pins to which the LCD is connected
const int rs = 8, en = 9, d4 = 10, d5 = 11, d6 = 12, d7 = 13;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); // Create an LCD object

// Declare variables for the numbers and operation
long Num1, Num2, Number;
char key, action;
boolean result = false;

void setup() {
  lcd.begin(16, 2); // Initialize the LCD with 16 columns and 2 rows
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
  if (key == '1') {
    Serial.println("Button 1");
    if (Number == 0)
      Number = 1;
    else
      Number = (Number * 10) + 1; // Append digit
  }
  
  if (key == '4') {
    Serial.println("Button 4");
    if (Number == 0)
      Number = 4;
    else
      Number = (Number * 10) + 4;
  }
  
  if (key == '7') {
    Serial.println("Button 7");
    if (Number == 0)
      Number = 7;
    else
      Number = (Number * 10) + 7;
  }
  
  if (key == '0') {
    Serial.println("Button 0");
    if (Number == 0)
      Number = 0;
    else
      Number = (Number * 10) + 0;
  }
  
  if (key == '2') {
    Serial.println("Button 2");
    if (Number == 0)
      Number = 2;
    else
      Number = (Number * 10) + 2;
  }
  
  if (key == '5') {
    Serial.println("Button 5");
    if (Number == 0)
      Number = 5;
    else
      Number = (Number * 10) + 5;
  }
  
  if (key == '8') {
    Serial.println("Button 8");
    if (Number == 0)
      Number = 8;
    else
      Number = (Number * 10) + 8;
  }

  if (key == '#') {
    Serial.println("Button Equal");
    Num2 = Number; // Store the second number
    result = true; // Set result flag
  }

  if (key == '3') {
    Serial.println("Button 3");
    if (Number == 0)
      Number = 3;
    else
      Number = (Number * 10) + 3;
  }
  
  if (key == '6') {
    Serial.println("Button 6");
    if (Number == 0)
      Number = 6;
    else
      Number = (Number * 10) + 6;
  }
  
  if (key == '9') {
    Serial.println("Button 9");
    if (Number == 0)
      Number = 9;
    else
      Number = (Number * 10) + 9;
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
