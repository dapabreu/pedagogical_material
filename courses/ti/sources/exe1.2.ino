int minimo=100, maximo=2000;
long numero=0;

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));
}

void loop() {
  numero = random(minimo, maximo+1);
  Serial.println(numero);
  Serial.println(numero%2==0);
  delay(1000);
}
