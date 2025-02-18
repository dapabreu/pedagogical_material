String numString;
int result;


void setup()
{
  Serial.begin(9600);
  Serial.println("Introduzir um numero + en formato String: ");
}

void loop()
{
  if (Serial.available()){
    numString = Serial.readStringUntil('\n');
    result = converteStr(numString);
    Serial.print("O resultado e: " + String(result));
  }	
}

int converteStr(String istr){
  int val = 0;
  int pot = 1;
  
  for (int i = istr.length()-1; i >= 0; i = i-1){
    if ((istr[i] >= '0') && (istr[i] <= '9')){
      val = val + (istr[i]-48)*pot;
      pot = pot*10;
    }else return (-1);
  }
  return(val);
}
