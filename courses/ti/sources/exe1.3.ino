int numero=0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  numero = numero +1;
  /* 
  Imprime o numero em formatos diferentes numa mesma linha
  */
  Serial.print(numero, DEC);
  Serial.print(" ");
  Serial.print(numero, HEX);
  Serial.print(" ");
  Serial.println(numero, BIN);
  delay(1000);
  //Serial.println();
}