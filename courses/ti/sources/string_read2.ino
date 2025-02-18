String a;

void setup() {
	Serial.begin(9600); 
  	Serial.println("Introduzir nome: ");
}

void loop() {
	
	// Ler uma string terminada por enter
	if (Serial.available()>0){	
      a = Serial.readStringUntil('\n');
      Serial.println("O seu nome e: " + a);
    }
}
