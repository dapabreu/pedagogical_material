int buttonPin1=7;
int buttonPin2=8;
int ledPin=13;


void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop(){
  int buttonState1 = !digitalRead(buttonPin1);
  int buttonState2 = !digitalRead(buttonPin2);
  
  Serial.print(buttonState1);
  Serial.print(" ");
  Serial.println(buttonState2);
  
  digitalWrite(ledPin, (buttonState1 && buttonState2));
}