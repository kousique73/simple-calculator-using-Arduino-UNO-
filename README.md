# 🧮 Simple Arduino Uno Calculator

[![Arduino](https://img.shields.io/badge/Platform-Arduino-00979D?style=for-the-badge&logo=Arduino&logoColor=white)](https://www.arduino.cc/)
[![Proteus](https://img.shields.io/badge/Simulation-Proteus-blue?style=for-the-badge)](https://www.labcenter.com/)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg?style=for-the-badge)](https://opensource.org/licenses/MIT)

A fully functional digital calculator built using the **Arduino Uno** microcontroller, a **16x2 LCD display**, and a **4x4 Matrix Keypad**. This repository includes multiple code implementations (both standard parallel LCD and I2C LCD connections) and simulation libraries for **Proteus Virtual System Modeling (VSM)**.

---

## 🚀 Key Features

*   **Multi-Digit Arithmetic**: Supports multi-digit operations for standard calculations.
*   **Core Math Operations**: Addition (`+`), Subtraction (`-`), Multiplication (`*`), and Division (`/`).
*   **Dual Display Modes**:
    *   **Parallel Interface**: Direct pin communication with standard 16x2 LiquidCrystal LCD.
    *   **I2C Interface**: Minimalist 2-wire serial connection using `LiquidCrystal_I2C`.
*   **User-Friendly Control**: Real-time display update, quick clear button (`*`), and immediate execution (`#`).
*   **Simulation Ready**: Complete with Proteus Arduino simulation libraries and design files for hardware-free testing.

---

## 📂 Repository Structure

```directory
├── calculator_file/
│   └── calculator_file.ino         # Main parallel LCD implementation (Optimized)
├── sketch_may23a/
│   └── sketch_may23a.ino           # Alternate parallel LCD code version
├── sketch_may26a/
│   └── sketch_may26a.ino           # I2C-enabled LCD implementation (Clean & modular)
├── Arduino Proteus Library/        # Arduino simulation model files for Proteus
│   ├── ARDUINO2.IDX
│   └── ARDUINO2.LIB
├── Keypad-master.zip               # Arduino Keypad library archive
├── I2C_LCD_Text_Error.zip          # Reference resources for resolving I2C display errors
├── hd44780-20240523T110438Z-001.zip# LCD controller documentation/library
└── README.md                       # This project guide
```

---

## 🔌 Hardware Configurations & Pin Maps

Depending on your hardware layout, choose one of the two setups below:

### 1. Parallel LCD Setup (`calculator_file.ino`)
Ideal for standard 16x2 LCD modules without an I2C adapter.

| LCD Pin | Arduino Pin | Description | Keypad Pin | Arduino Pin | Description |
| :---: | :---: | :--- | :---: | :---: | :--- |
| **RS** | Pin 8 | Register Select | **ROW 0** | Pin 0 | Keypad Row 0 |
| **EN** | Pin 9 | Enable Signal | **ROW 1** | Pin 1 | Keypad Row 1 |
| **D4** | Pin 10 | Data Bus 4 | **ROW 2** | Pin 2 | Keypad Row 2 |
| **D5** | Pin 11 | Data Bus 5 | **ROW 3** | Pin 3 | Keypad Row 3 |
| **D6** | Pin 12 | Data Bus 6 | **COL 0** | Pin 4 | Keypad Col 0 |
| **D7** | Pin 13 | Data Bus 7 | **COL 1** | Pin 5 | Keypad Col 1 |
| | | | **COL 2** | Pin 6 | Keypad Col 2 |
| | | | **COL 3** | Pin 7 | Keypad Col 3 |

### 2. I2C LCD Setup (`sketch_may26a.ino`)
Uses only two signal wires (SDA & SCL), saving digital pins for other components.

| LCD I2C Module Pin | Arduino Pin | Description | Keypad Pin | Arduino Pin | Description |
| :---: | :---: | :--- | :---: | :---: | :--- |
| **SDA** | SDA (A4) | Serial Data Line | **ROW 0** | Pin 2 | Keypad Row 0 |
| **SCL** | SCL (A5) | Serial Clock Line | **ROW 1** | Pin 3 | Keypad Row 1 |
| **VCC** | 5V | Power Supply | **ROW 2** | Pin 4 | Keypad Row 2 |
| **GND** | GND | Ground | **ROW 3** | Pin 5 | Keypad Row 3 |
| | | | **COL 0** | Pin 6 | Keypad Col 0 |
| | | | **COL 1** | Pin 7 | Keypad Col 1 |
| | | | **COL 2** | Pin 8 | Keypad Col 2 |
| | | | **COL 3** | Pin 9 | Keypad Col 3 |

---

## ⌨️ Keypad Mapping

The keypad uses custom layouts mapped to perform arithmetic functions:

### Parallel Layout (`calculator_file.ino` / `sketch_may23a.ino`)
```
 ┌───┬───┬───┬───┐
 │ 7 │ 8 │ 9 │ / │  <-- 'D' is mapped to Division (/)
 ├───┼───┼───┼───┤
 │ 4 │ 5 │ 6 │ * │  <-- 'C' is mapped to Multiplication (*)
 ├───┼───┼───┼───┤
 │ 1 │ 2 │ 3 │ - │  <-- 'B' is mapped to Subtraction (-)
 ├───┼───┼───┼───┤
 │ C │ 0 │ = │ + │  <-- '*' is Clear, '#' is Equal, 'A' is Addition (+)
 └───┴───┴───┴───┘
```

### I2C Layout (`sketch_may26a.ino`)
```
 ┌───┬───┬───┬───┐
 │ 1 │ 2 │ 3 │ + │  <-- 'A' is mapped to Addition (+)
 ├───┼───┼───┼───┤
 │ 4 │ 5 │ 6 │ - │  <-- 'B' is mapped to Subtraction (-)
 ├───┼───┼───┼───┤
 │ 7 │ 8 │ 9 │ * │  <-- 'C' is mapped to Multiplication (*)
 ├───┼───┼───┼───┤
 │ C │ 0 │ = │ / │  <-- '*' is Clear, '#' is Equal, 'D' is Division (/)
 └───┴───┴───┴───┘
```

---

## 🛠️ Software Setup & Installation

### 1. Library Dependencies
Make sure you have the following libraries installed in your Arduino IDE:
*   [Keypad Library](https://github.com/Chris-M-Frierson/Keypad) (Included in `Keypad-master.zip`)
*   [LiquidCrystal I2C Library](https://github.com/johnrickman/LiquidCrystal_I2C) (If using the I2C version)

### 2. Flashing the Code
1. Open the [Arduino IDE](https://www.arduino.cc/en/software).
2. Connect your Arduino Uno board to your computer.
3. Open either `calculator_file/calculator_file.ino` (Parallel) or `sketch_may26a/sketch_may26a.ino` (I2C).
4. Select your board (**Tools > Board > Arduino Uno**) and the corresponding port (**Tools > Port**).
5. Click **Upload** (right arrow icon) to flash the code to your Arduino Uno.

---

## 🧪 Proteus Simulation Setup

You can fully simulate this project using **Proteus ISIS**:

1.  **Install Arduino Proteus Library**:
    *   Copy `ARDUINO2.IDX` and `ARDUINO2.LIB` from the `Arduino Proteus Library/` directory.
    *   Paste them into your Proteus library directory (usually `C:\Program Files (x86)\Labcenter Electronics\Proteus 8 Professional\Data\LIBRARY`).
2.  **Generate Hex File in Arduino IDE**:
    *   In Arduino IDE, go to **File > Preferences**.
    *   Check the box for `Show verbose output during: compilation`.
    *   Compile the sketch (Verify icon).
    *   Locate the generated `.hex` file path in the compile log console at the bottom of the IDE.
3.  **Load Hex File in Proteus**:
    *   Double-click the Arduino Uno component in your Proteus schematic design.
    *   In the **Program File** field, paste the path to your `.hex` file.
    *   Click **Run** to start the simulation.

---

## 📝 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

*Developed as part of the **CSE-331** course project.*