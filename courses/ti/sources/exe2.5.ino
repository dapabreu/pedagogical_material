byte count=0;
byte const BLUE=4, RED=3, GREEN=5;

void setup(){
  Serial.begin(9600);
  for (int pin=3;pin<=13;pin++)
  	pinMode(pin, OUTPUT);
}

void loop(){
  genLEDBin(count, 6);
  
  digitalWrite(RED,(count<=100));
  digitalWrite(GREEN,((count>=101) && (count<=200)));  
  digitalWrite(BLUE,(count>=201));

  Serial.println(count);
  count=count+1;
  delay(100);
}

void genLEDBin(byte count, byte LEDoffset){
  for (int digit=0;digit<8;digit++)
    digitalWrite(LEDoffset+digit,(count>>digit)&1);
  //return;
}
