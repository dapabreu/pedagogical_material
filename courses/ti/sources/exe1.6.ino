int led1Pin=12, led2Pin=13;
int btnPin = 7;

void setup()
{
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  pinMode(btnPin, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop()
{
  bool btnStatus = !digitalRead(btnPin);
  Serial.println(btnStatus);
  digitalWrite(led1Pin, btnStatus);
  digitalWrite(led2Pin, !btnStatus);
}
