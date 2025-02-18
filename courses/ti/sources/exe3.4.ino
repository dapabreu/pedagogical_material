const int LEDRED=11;
const int LEDBLUE=10;
const int LEDGREEN=9;
int min=0, max=1024;
int number;
int numberUser;
int time = 500;
float intensity;
String readStr;

bool newNumber = false;

void setup() {
  pinMode(13, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  
  randomSeed(analogRead(0));
  
  Serial.begin(9600);
}

void loop() {
  
  if (!newNumber) {
  	number = random(min, max+1);
    newNumber = true;
    Serial.println("A new random number was generated.");
    Serial.println(number);
    Serial.println("Guessing - Introduce a number: ");
  }
  
  if (Serial.available() > 0){
    readStr = Serial.readStringUntil('\n');
    numberUser = readStr.toInt();
    Serial.println(numberUser);
    
    guessing();
    if (newNumber)
      Serial.println("Guessing - Introduce a number: ");
  }
  
  delay(2000);
}

void guessing() {
  if (numberUser > number) {
    intensity = 255 - ((numberUser - number) * (255.0 / 1024.0));
    Serial.println(intensity);
    analogWrite(LEDRED, intensity);
    delay (time);
  	digitalWrite(LEDRED,LOW);
  }
  if (numberUser < number) {
    intensity = 255 - ((number - numberUser) * (255.0 / 1024.0));
    Serial.println(intensity);
    analogWrite(LEDRED, intensity);
    analogWrite(LEDGREEN, intensity);
    delay (time);
  	digitalWrite(LEDRED,LOW);
    digitalWrite(LEDGREEN,LOW);
  }
  if (numberUser == number) {
    analogWrite(LEDGREEN, 255);
    delay (time * 4);
    digitalWrite(LEDGREEN,LOW);
    newNumber = false;
  }
}
