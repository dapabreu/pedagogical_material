byte largura_base=9;

void setup()
{
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
    digitalWrite(13,LOW); 

    //Vai acabar por se concluir que isto nao faz falta nenhuma…
    if (largura_base<=9){
		if ((largura_base%2==0) && (largura_base<=8)) 
          largura_base++;
    
    	//talvez a contagem decrescente seja muito para eles…
    
        //e o segundo ciclo podia ser uma contagem de impares…
    	for (int linha=largura_base/2;linha>=0; linha--){
      		for (int coluna=0;coluna<(largura_base-linha);coluna++)
      		{
      			if (coluna<linha) 
                  //Serial.print("-");
                  Serial.print(" ");
      			else 
                  Serial.print("*");
      		}
      		Serial.println();
    	}
    	digitalWrite(13,HIGH);
    	delay(1000);
      	digitalWrite(13,LOW);
        delay(1000); 
  	}  
}
