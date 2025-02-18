int salto=3;
int n=0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println(n);
  n=n+salto;
  delay(1000);
}
