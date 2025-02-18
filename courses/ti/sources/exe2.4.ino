void setup()
{
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  for (int cont=200;cont<=400;cont++){
    Serial.print("Value cont: ");
    Serial.print(cont);
    Serial.print(" | ");
    digitalWrite(13,(cont%2==0)); 
    Serial.print("Pin 13: ");
    Serial.print(cont%2==0);
    Serial.print(" | ");
    digitalWrite(12,(cont%3==0));
	Serial.print("Pin 12: ");
    Serial.println(cont%3==0);
    if ((cont%2==0) || (cont%3==0)) 
      delay(2000);
    }
}
