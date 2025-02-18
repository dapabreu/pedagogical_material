const int buzzer = 2;
const int ledNum = 3;
const int rgbG = 4;
const int rgbB = 5;
const int rgbR = 6;
const int waitingTime = 1000;
boolean initSystem = false;
boolean event = false;
int ldrStatus;
int counter = 0;
unsigned long iniTime = 0;
float voltage;

void setup()
{
  Serial.begin(9600);
  for (int i = 2; i <= 6; i++)
     pinMode(i, OUTPUT);
}

void loop()
{
  if (initSystem == false){
    //Initializing the security system
    Serial.println("Initializing the security system!");
    //Initial time
    iniTime = millis();
    digitalWrite(rgbR, HIGH);
    delay(waitingTime);
    Serial.println("Security system ready!");
    digitalWrite(rgbR, LOW);
    digitalWrite(rgbG, HIGH);
    initSystem = true;
  }
  //Reading ldr
  ldrStatus = analogRead(A0);
  voltage = (ldrStatus / 1023.0) * 5;  //LDR voltage
  Serial.println("LDR | " + String(ldrStatus) + " | " + String(voltage));
  if ((voltage < 1) && event){
  	//Turning off the buzzer
    Serial.println("The event is gone. Turning off the buzzer at the time: " + String(millis() - iniTime));
    digitalWrite(buzzer, LOW);
    event = false;
  }else{
    //First time that event is detected
    if ((voltage >= 1) && (counter == 0)){
      event = true;
      counter = counter + 1;
      digitalWrite(buzzer, HIGH);
      //Setting intensity to the first level
      analogWrite(ledNum, 85);
      digitalWrite(rgbG, LOW);
      digitalWrite(rgbB, HIGH);
      Serial.println("Event detected. The number of occurrences is " + String(counter) + " at the time: " + String(millis() - iniTime));
    }
    if ((voltage >= 1) && (counter > 0)){
      event = true;
      counter = counter + 1;
      digitalWrite(buzzer, HIGH);
	  //Setting intensity accordingly to 2 or 3 level
      if (counter == 10)
        analogWrite(ledNum, 170);
      if (counter >= 20)
        analogWrite(ledNum, 255);
      Serial.println("Event detected. The number of occurrences is " + String(counter) + " at the time: " + String(millis() - iniTime));
    }
  }
  delay(waitingTime);
}
