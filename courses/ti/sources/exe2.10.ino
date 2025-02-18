int led0Pin= 10, led1Pin= 11, led2Pin= 12, led3Pin= 13;
int btnPin= 7;
long randNumber;
long randNumberShift;
long mask = 0b00000000000000000000000000001111;
bool flag= false;
int counter;
int toPrint;

void setup()
{
  pinMode(led0Pin, OUTPUT);
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  pinMode(led3Pin, OUTPUT);
  pinMode(btnPin, INPUT_PULLUP);
  randomSeed(analogRead(0));
  Serial.begin(9600);
}

void loop()
{
  if (!flag){
    Serial.print("The random number will be generated --> ");
    randNumber = random(2147483647);
    randNumberShift = randNumber;
    Serial.print(randNumber,DEC);
    Serial.print(" ");
    Serial.println(randNumber,BIN);
    flag= true;
  }
  
  bool btnStatus = !digitalRead(btnPin);
  
  if(btnStatus){
    toPrint= randNumberShift & mask;
    randNumberShift= randNumberShift >> 4;
    Serial.print(toPrint,BIN);
    Serial.print(" ");
    Serial.println(randNumberShift,BIN);
    digitalWrite(13,(toPrint&0b1000));
    digitalWrite(12,(toPrint&0b0100));
    digitalWrite(11,(toPrint&0b0010));
    digitalWrite(10,(toPrint&0b0001));
    counter++;
    delay(2000);  	
  }
  
  if (counter == 8){
    flag= false;
    counter= 0;
    digitalWrite(13,LOW);
    digitalWrite(12,LOW);
    digitalWrite(11,LOW);
    digitalWrite(10,LOW);
  }
}
