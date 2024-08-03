#include <LiquidCrystal.h>

const int lumos = 7;
const int photoresistor = A0;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  pinMode(lumos, OUTPUT);
  digitalWrite(lumos, LOW);
}

void lumos_automata() {
  int val = analogRead(photoresistor);

  //Serial.println(val); // Can help to debug if you try to find the right value
  if (val <= 80) { // This value can change du to the room, where you place the arduino ...
    //Serial.println("Status lamp :OFF");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Status lamp :OFF");
    digitalWrite(lumos, LOW);
  } else {
    //Serial.println("Status lamp :ON");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Status lamp :ON");
    digitalWrite(lumos, HIGH);
  }
}

void loop() {
  lumos_automata()
  delay(1000);
}
