const int lumos = 7;

void setup() {
  Serial.begin(9600);
  pinMode(lumos, OUTPUT);
  digitalWrite(lumos, LOW);
}



void loop() {
  delay(1000);
}
