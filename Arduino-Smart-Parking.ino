#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Initialize LCD and Servo
LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo myservo;

// Define sensors
const int IR1 = 2;
const int IR2 = 3;

// Total and available parking slots
int totalSlots = 6; // Total number of parking slots
int availableSlots = 6; // Available parking slots

// Define flags for sensor states
bool flag1 = false;
bool flag2 = false;

void setup() {
  // Initialize the servo
  myservo.attach(4);
  myservo.write(100);

  // Initialize the LCD
  lcd.init();
  lcd.backlight();

  // Set up sensor pins
  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);

  // Initialize serial communication
  Serial.begin(9600);

  // Display startup message
  lcd.setCursor(0, 0);
  lcd.print(" ARDUINO PARKING ");
  lcd.setCursor(0, 1);
  lcd.print("     SYSTEM      ");
  delay(2000);
  lcd.clear();
}

void loop() {
  // Check the first sensor (entry)
  if (digitalRead(IR1) == LOW && !flag1) {
    if (availableSlots > 0) {
      flag1 = true;
      if (!flag2) {
        myservo.write(0);
        availableSlots--; // Decrease available slots
      }
    } else {
      displayMessage(" SORRY :( ", " Parking Full ");
    }
  }

  // Check the second sensor (exit)
  if (digitalRead(IR2) == LOW && !flag2) {
    flag2 = true;
    if (!flag1) {
      myservo.write(0);
      availableSlots++; // Increase available slots
    }
  }

  // Reset the servo after passing
  if (flag1 && flag2) {
    delay(1000);
    myservo.write(100);
    flag1 = false;
    flag2 = false;
  }

  // Update the main display
  displayStatus();
}

void displayMessage(String line1, String line2) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(line1);
  lcd.setCursor(0, 1);
  lcd.print(line2);
  delay(3000);
  lcd.clear();
}

void displayStatus() {
  lcd.setCursor(0, 0);
  lcd.print("    WELCOME!    ");
  lcd.setCursor(0, 1);
  lcd.print("Slot Left: ");
  lcd.print(availableSlots); // Display available slots
}

