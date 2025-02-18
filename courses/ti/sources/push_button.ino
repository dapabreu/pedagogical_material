int buttonPin=7;
int ledPin=13;

void setup(){
  	Serial.begin(9600);
	pinMode(ledPin,OUTPUT);
  	pinMode(buttonPin,INPUT);
}

void loop(){
  int buttonState=digitalRead(buttonPin);
  digitalWrite(ledPin,buttonState);
  Serial.println(buttonState);
  delay(1000);
}
