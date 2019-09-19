const int ledPin = 13;
int previousTCNT = 0;
unsigned long previousMillis = 0;
const int interval = 1000;

void setup() {
  Serial.begin(9600);
  TCCR1A = 0x00;
  TCCR1B |= _BV(CS12);
  TCCR1B |= _BV(CS11);
  TCCR1B |= _BV(CS10);
  TCNT1 = 0;
}

void loop() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis > interval) {
    Serial.print("TCNT1: ");
    Serial.println(TCNT1);
    previousMillis = currentMillis;
  }
  if (TCNT1%2 == 0) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
}
