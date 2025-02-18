unsigned  result=0;

void setup() {
  Serial.begin(9600);
  int x= -16, y=2;
  result = (x >> y);
  Serial.println(result, BIN);  
}

void loop(){
}
