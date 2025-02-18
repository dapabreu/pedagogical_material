int buttonPin=7;
int ledPin=13;
int count = 0;

void setup(){
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop(){
  int buttonState = !digitalRead(buttonPin);
  digitalWrite(ledPin, buttonState);
  
  if (buttonState){
  	count = count + 1;
    Serial.println(count);
  }
}
