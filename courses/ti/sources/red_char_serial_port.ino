char incomingByte = 0;

void setup() {
  Serial.begin(9600); 
  Serial.println("START");
}

void loop() {
  if (Serial.available() > 0) {
    incomingByte = Serial.read();

    Serial.print("I received (value/code ASCII): ");
    Serial.println(incomingByte, DEC);
    Serial.print("I received (CHAR): ");
    Serial.println(incomingByte);
  }
}
