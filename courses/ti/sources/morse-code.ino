unsigned int led_pin = 12;
unsigned int dot_duration = 200;
char ch;
bool done = false;

// The numbers 0-9 in Morse code 
String numbers[] = {"-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."};

void setup() {
  pinMode(led_pin, OUTPUT);
  Serial.begin(9600); 
   
  Serial.println("MORSE CODE LED PROGRAM");
  Serial.println("");
  Serial.println("Enter your message(s) or ! to exit: ");
}

void loop() {
  while (!done) {
    if (Serial.available()) {     
      ch = Serial.read();
      
      if (ch >= '0' && ch <= '9') {
        Serial.println(ch);
        flash_morse_code(numbers[ch - '0']);
      }
      else {
        if (ch == '!') {
          done = true;  
          Serial.println("Your messages were successfully sent. Bye, bye.");
      	}
        else{
        	done = true;  
          	Serial.println("The message was not valid.");
        }
      }
    }
  }                 
}

void flash_morse_code(String morse_code) {
  unsigned int i = 0;
    
  while (morse_code[i] != NULL) {    
    digitalWrite(led_pin, HIGH);
    
    if (morse_code[i] == '.') {
      delay(dot_duration);           
  	}
    else {
    	delay(dot_duration * 3);           
  	}
    
    digitalWrite(led_pin, LOW);
    delay(dot_duration); 
    i++;
  }
}