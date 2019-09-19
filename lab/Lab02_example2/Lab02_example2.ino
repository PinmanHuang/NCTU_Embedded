const int ledPin = 13;
void setup() {
  pinMode(ledPin, OUTPUT);
  TCCR1A = 0x00;
  TCCR1B |= _BV(CS12);
  TCCR1B &= ~_BV(CS11);
  TCCR1B |= _BV(CS10);
  TCNT1 = 0;
}

void loop() {
  digitalWrite(ledPin, HIGH);
  delay1s();
  digitalWrite(ledPin, LOW);
  delay1s();
}

void delay1s() {
  while (TCNT1 < 15625/2)
  ;
  TCNT1 = 0;
}
