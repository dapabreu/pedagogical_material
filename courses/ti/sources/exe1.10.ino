//int pinButton=7;
int contador=0, ledAcesso=0;
int led1=13;

void setup()
{
  //pinMode(pinButton, INPUT_PULLUP);
  pinMode(led1, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  //bool btnState = !digitalRead(pinButton);
  
  //if (btnState){
    //contador++;
    Serial.println(contador);
    if (contador%3==0) { 
      ledAcesso ++;
      digitalWrite(led1, HIGH);    
      Serial.print("Led Acesso: ");
      Serial.println(ledAcesso);
    }else {
      digitalWrite(led1, LOW);      
    }
  	contador ++;
  	delay(1000);
  //} 
}
