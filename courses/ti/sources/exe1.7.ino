bool trueReading=false;
bool lastState=false;

//Nota: 50ms é um bom valor para o mundo real
//mas no tinkercad é algo lento - ajustado para 20
unsigned long debounceDelay=20;
unsigned long bounce;
int count=0;

void setup(){
  pinMode(7,INPUT_PULLUP);
  pinMode(12,OUTPUT);
  Serial.begin(9600);
}

void loop(){
  bool btt=!(digitalRead(7));
  Serial.print("Pin 7: ");
  Serial.println(btt);
  Serial.println("---");
  Serial.print("lastState ");
  Serial.println(lastState);

  if (btt!=lastState) {
    bounce=millis();
  }

  if ((millis()- bounce)> debounceDelay){
    if (btt!=trueReading) {
      trueReading=btt;

      if (trueReading==true) {
        count=count+1;

        if (count>=3) {
          digitalWrite(12,HIGH);
          delay(500);
          digitalWrite(12,LOW);
          delay(500);
          count=0;
        }
      }
    }
  }
  lastState=btt;
}
