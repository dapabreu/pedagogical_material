int val=4;


void setup()
{
  Serial.begin(9600);

  int res=val & (val-1);
  if ((val>=2) && (res==0)) Serial.println(String(val)+" sim");
  else Serial.println(String(val)+" nao");
}

void loop()
{

}
