#include <LiquidCrystal.h>

// Initialize the LCD with the appropriate pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Define pin numbers
const int sensorPin = 9;  // PIR sensor pin
const int buzzerPin = 7;  // Buzzer pin

// Variables to track sensor state
int sensorState = LOW;    // Current state of the sensor
int previousState = LOW;  // Previous state of the sensor

void setup() {
  // Set up the sensor and buzzer pins
  pinMode(sensorPin, INPUT);
  pinMode(buzzerPin, OUTPUT);

  // Initialize the LCD
  lcd.begin(16, 2);
  lcd.print("STATUS: ");
  delay(2000); // Display the initial message for 2 seconds
  lcd.clear();
}

void loop() {
  // Read the current state of the sensor
  sensorState = digitalRead(sensorPin);

  if (sensorState == HIGH && previousState == LOW) {
    // Motion detected
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Contamination");
    lcd.setCursor(0, 1);
    lcd.print("Found!");
    digitalWrite(buzzerPin, HIGH); // Activate the buzzer
    previousState = HIGH;
  } else if (sensorState == LOW && previousState == HIGH) {
    // No motion detected
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("No");
    lcd.setCursor(0, 1);
    lcd.print("Contamination");
    digitalWrite(buzzerPin, LOW); // Deactivate the buzzer
    previousState = LOW;
  }
}
