int a=0;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  Serial.println("Hello world!!!");
  Serial.println(a);
  a=a+1;

}

