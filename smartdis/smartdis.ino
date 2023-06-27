#include <LiquidCrystal.h>

const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int pingPin = 8; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 9; // Echo Pin of Ultrasonic Sensor
int btn=A0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(btn,INPUT);
 lcd.begin(16, 2);
 lcd.clear();
  // Print a message to the LCD.
  lcd.print("Smart Blind");
  lcd.setCursor(0,1);
  lcd.print("Distance Monitor");
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:

long duration, inches, cm;
   pinMode(pingPin, OUTPUT);
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin, LOW);
   pinMode(echoPin, INPUT);
   duration = pulseIn(echoPin, HIGH);
   inches = microsecondsToInches(duration);
   cm = microsecondsToCentimeters(duration);
   if(digitalRead(btn)==1)
   {Serial.println(cm);

   lcd.begin(16, 2);
 lcd.clear();
  // Print a message to the LCD.
  lcd.print("Distance Measured");
  lcd.setCursor(0,1);
  lcd.print(cm);
  delay(1000);
   }
}

long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}

