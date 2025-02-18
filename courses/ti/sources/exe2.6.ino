boolean buttonReading=false;
boolean prevStatus=false;
boolean buttonStatus=false;
unsigned long debounceDelay = 20;
int count=0;
unsigned long ellapsed;

void setup(){
  for (int res=11;res<=13;res++)
    pinMode(res,OUTPUT);
  pinMode(7, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop(){
  buttonReading=!digitalRead(7);
  
  //Reset ao contador do debouncer
  if (buttonReading!=prevStatus)
    	ellapsed=millis();
 //Se passou um intervalo de tempo seguro
  if ((millis()-ellapsed)>debounceDelay){
    //e o estado do botao realmente mudou
    //(sem que tenha havido resets)
    //entao assume o estado novo para o botao
    if (buttonStatus!=buttonReading) {
    	buttonStatus=buttonReading;
		if (buttonStatus) count=(count+1)%8;	 
    }
    if (buttonStatus && (millis()-ellapsed>2000)) {
		count=0;
	    ellapsed=millis();
    }
  }
  
  gen3LEDBin(count,11);
  prevStatus=buttonReading;
}

void gen3LEDBin(byte number, byte LEDoffset) {
 for (int digit=0;digit<3;digit++)	 	
   digitalWrite(LEDoffset+digit,(number>>digit)&1);
}
