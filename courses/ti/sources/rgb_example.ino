const int LEDRED=13;
const int LEDBLUE=11;
const int LEDGREEN=10;

void setup()
{
  pinMode(13, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop()
{
  digitalWrite(LEDRED, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(LEDRED, LOW);
  digitalWrite(LEDBLUE, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(LEDBLUE, LOW);
  digitalWrite(LEDGREEN, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(LEDGREEN, LOW);
}
