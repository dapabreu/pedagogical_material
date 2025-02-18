int val=1;

void setup()
{
  pinMode(7, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop()
{
  if (!digitalRead (7)){
    while(val<=100) {
        Serial.print(val);
      	Serial.print(" ");
      	Serial.println(val, BIN);
        val=val<<1;
    }
    delay(200);
  }
  val=1;
}
