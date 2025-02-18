int value= 500;
int min=100, max=2000;
long number=0;

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));
}

void loop() {
  int dif = 0;
    
  number = random(min, max+1);
  
  if(value>=number){
  	dif = value - number; 
  }else{
    dif = number - value;
  }
  
  
  Serial.print(value);
  Serial.print(" ");
  Serial.print(number);
  Serial.print(" ");
  Serial.println(dif);
  delay(1000);
}
