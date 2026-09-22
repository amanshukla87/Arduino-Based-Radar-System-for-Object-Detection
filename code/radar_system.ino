#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo radarServo;

// Pin assignments from the project hardware setup
const int trigPin = 10;
const int echoPin = 11;
const int servoPin = 9;
const int greenLed = 2;
const int redLed = 3;
const int buzzer = 8;

const int safeDistance = 20; // Alert threshold in cm
long duration;
int distance;

void setup() {
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(buzzer, OUTPUT);

  radarServo.attach(servoPin);

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
  // Sweep from 0 to 180 degrees
  for (int angle = 0; angle <= 180; angle += 2) {
    radarServo.write(angle);
    delay(30);
    distance = measureDistance();
    handleAlertsAndDisplay(angle, distance);
  }

  // Sweep back from 180 to 0 degrees
  for (int angle = 180; angle >= 0; angle -= 2) {
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
  if (duration == 0) return 400;

  return duration * 0.034 / 2;
}

void handleAlertsAndDisplay(int angle, int dist) {
  Serial.print(angle);
  Serial.print(",");
  Serial.print(dist);
  Serial.print(".");

  lcd.setCursor(0, 0);
  lcd.print("Angle: ");
  lcd.print(angle);
  lcd.print(" deg   ");

  lcd.setCursor(0, 1);
  if (dist <= safeDistance && dist > 0) {
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
    digitalWrite(buzzer, HIGH);

    lcd.print("Obj: ");
    lcd.print(dist);
    lcd.print(" cm WARN!");
  } else {
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);
    digitalWrite(buzzer, LOW);

    lcd.print("Status: CLEAR   ");
  }
}
