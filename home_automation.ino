#include <LiquidCrystal.h>
#include <DHT.h>

const int lumos = 7;
const int photoresistor = A0;
int windows = 0;
const int buttonNext = 9;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
DHT dht(8, DHT11);

void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  dht.begin();
  pinMode(lumos, OUTPUT);
  pinMode(buttonNext, INPUT);
  digitalWrite(lumos, LOW);
}

void get_meteo() {
  int humidity = dht.readHumidity();
  int temp = dht.readTemperature();

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(String(temp));
  lcd.print(" degres | ");
  lcd.print(String(humidity));
  lcd.print(" %");
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

void switch_window() {
  int buttonState = digitalRead(buttonNext);
  int already_press = 0;
  
  if (buttonState == HIGH && already_press == 0) {
    windows++;
    already_press = 1;
  }
  delay(500);
}

void loop() {
  switch_window();
  switch(windows % 2) {
    case 0:
      lumos_automata();
      break;
    case 1:
      get_meteo();
      break;
    default:
      Serial.println("ERROR OCCURED");
  }
  delay(1000);
}
