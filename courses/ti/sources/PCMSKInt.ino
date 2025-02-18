const byte ledPin = 13;

volatile byte state = LOW;

void setup(){
  pinMode(ledPin, OUTPUT);
  pinMode(A0, INPUT_PULLUP);
  PCMSK1 = B00000001; //enable PCINT8
  PCIFR = B00000000; // clear all interrupt flags
  PCICR = B00000010; // enable PCIE1 group
}

void loop(){
  digitalWrite(ledPin, state);
}

ISR(PCINT1_vect) {
  state = !state;
}