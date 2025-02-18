long randNumber;

void setup(){
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("Starting the program!");
}

void loop(){
  randNumber = random(0, 1000); 
  
  Serial.print("The number ");
  Serial.print(randNumber);
  Serial.print(" is ");
  Serial.println(check_even(randNumber));
  delay(1000);
  
}

bool check_even(int x){
	if (x%2 == 0)
      return(true);
  	else
      return(false);
}
