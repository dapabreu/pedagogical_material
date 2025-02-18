int val=1;

void setup()
{
  pinMode(13, OUTPUT);
  pinMode(7, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop()
{
  if (!digitalRead (7)){
    for (int c=0;c<4;c++){
        Serial.print(val);
      	Serial.print(" ");
      	Serial.println(val, BIN);
        val=val<<1;
    }
  }
  val=1;
  delay(1000);
}
