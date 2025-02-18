String a;
int valor;

void setup() {
	Serial.begin(9600); 
  	Serial.println("Introduzir nome: ");
}

void loop() {	
    /*Ler uma string terminada por Enter
     Primeiro passo: verificar se existem dados na porta
     serie para receber, com o Serial.available() */

    if (Serial.available()>0) {	
	/* Segundo passo: ler os dados utilizando o 
    readStringUntil (o que sera o ‘\n’?) */

	a= Serial.readStringUntil('\n');
	Serial.println("O seu nome e: "+a);
      
	//Conversao para inteiro, demonstracao
	valor=a.toInt();
	valor=valor+1; 
	Serial.println(valor);
      
	/*A funcao String() converte numeros em cadeias de 	carateres - o segundo parametro,
    que e opcional, permite especificar a base (como no println) */
      Serial.println("O valor binario e: "+String(valor,BIN));
    }
}
