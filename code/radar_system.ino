#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

// I2C Address is usually 0x27 or 0x3F for 16x2 displays
LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo radarServo;

// Pin Assignments based on your setup
const int trigPin = 9;
const int echoPin = 10;
const int servoPin = 11;
const int greenLed = 12;
const int redLed = 13;
const int buzzer = 8;

const int safeDistance = 20; // Alert threshold in cm
long duration;
int distance;

void setup() {
  // Start Serial communication at 9600 baud for Processing
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(buzzer, OUTPUT);

  radarServo.attach(servoPin);

  // Initialize I2C LCD
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print(" RADAR SYSTEM ");
  lcd.setCursor(0, 1);
  lcd.print(" INITIALIZING ");
  delay(2000);
  lcd.clear();
}

void loop() {
  // Sweep from 15 to 165 degrees
  for (int angle = 15; angle <= 165; angle += 2) {
    radarServo.write(angle);
    delay(30);
    distance = measureDistance();
    handleAlertsAndDisplay(angle, distance);
  }

  // Sweep back from 165 to 15 degrees
  for (int angle = 165; angle >= 15; angle -= 2) {
    radarServo.write(angle);
    delay(30);
    distance = measureDistance();
    handleAlertsAndDisplay(angle, distance);
  }
}

int measureDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH, 30000);
  if (duration == 0) return 400; // Default max distance
  return duration * 0.034 / 2;
}

void handleAlertsAndDisplay(int angle, int dist) {
  // Send formatted data to Processing via Serial
  Serial.print(angle);
  Serial.print(",");
  Serial.print(dist);
  Serial.print(".");

  // Update LCD display
  lcd.setCursor(0, 0);
  lcd.print("Angle: ");
  lcd.print(angle);
  lcd.print(" deg   ");

  lcd.setCursor(0, 1);
  if (dist <= safeDistance && dist > 0) {
    // Danger State
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
    digitalWrite(buzzer, HIGH);

    lcd.print("Obj: ");
    lcd.print(dist);
    lcd.print(" cm WARN!");
  } else {
    // Clear State
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);
    digitalWrite(buzzer, LOW);

    lcd.print("Status: CLEAR   ");
  }
}
