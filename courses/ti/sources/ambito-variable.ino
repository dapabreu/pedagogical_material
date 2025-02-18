int a=0;

void setup()
{
  int local=100;
  Serial.begin(9600);
}

void loop()
{
  a=a+1;
  Serial.println(a);
  Serial.println(local);	
}
