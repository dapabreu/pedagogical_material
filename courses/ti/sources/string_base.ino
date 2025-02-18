void setup()
{
  Serial.begin(9600);
}

void loop()
{
  String myString = String(13);
  Serial.println(myString);
  myString = String(13, HEX);
  Serial.println(myString);
  myString = String(13, BIN);
  Serial.println(myString);
  delay(2000);
}
