int incomingByte = 0; // variável para o dado recebido

void setup() {
  Serial.begin(9600); 
}

void loop() {
  // apenas responde quando dados são recebidos:
  if (Serial.available() > 0) {
    // lê do buffer o dado recebido:
    incomingByte = Serial.read();

    // responde com o dado recebido:
    Serial.print("I received: ");
    Serial.println(incomingByte, DEC);
  }
} 
