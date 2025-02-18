const int LED = 9;
int val = 0;

void setup(){
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop(){
  Serial.println("Reading analog pin");
  val = analogRead(0);
  Serial.println(val);
  Serial.println("Setting led intensity");
  analogWrite(LED, val/4);
  Serial.println("Delay");
  delay(1000);
}
