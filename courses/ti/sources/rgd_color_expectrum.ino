const int LEDRED=11;
const int LEDBLUE=10;
const int LEDGREEN=9;

void setup()
{
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop()
{
  for(int i = 0; i < 255; i++){
  	analogWrite(LEDRED, i);
    analogWrite(LEDGREEN, 255 - i);
    analogWrite(LEDBLUE, 0);
  	delay(10);
  }
  for(int i = 0; i < 255; i++){
  	analogWrite(LEDRED, 255 - i);
    analogWrite(LEDGREEN,0);
    analogWrite(LEDBLUE, i);
  	delay(10);
  }
  for(int i = 0; i < 255; i++){
  	analogWrite(LEDRED, 0);
    analogWrite(LEDGREEN,i);
    analogWrite(LEDBLUE, 255 - i);
  	delay(10);
  }
  
}
