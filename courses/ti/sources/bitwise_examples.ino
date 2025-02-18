
void setup() {
  Serial.begin(9600);
  int n1=20; //b10100 
  int n2=19; //b10011
  int n3=8; //b1000
  
  Serial.println("Numeros ");
  Serial.println(n1, BIN);
  Serial.println(n2, BIN);
  Serial.println(n3, BIN);
 
  //Que operações binárias pode(m) ser feita com os 3 numeros 
  // para o resultado ser 31 ? (b11111)
  
  // Hipótese -- OU
  int n4 = n1 | n2 | n3 ;
  Serial.println(n4,BIN);

  // Hipótese -- OU e XOR
  n4 = n1 | n2 ^ n3 ;
  Serial.println(n4,BIN);

  //Que operações binárias pode(m) ser feita com os 3 numeros 
  // para o resultado ser 0 ? (b0)
  //Hipótese -- E
  n4 = n1 & n2 & n3;
  Serial.println(n4,BIN); 
}

void loop(){
}


/*
void setup(){
  Serial.begin(9600);
  int n1=0b0101; //5, em decimal
  int n2=0b0110; //6, em decimal

  Serial.println("Operador binário E ");
  Serial.println(n1 & n2,DEC);
  Serial.println(n1 & n2,BIN);

  Serial.println("Operador binário OU ");
  Serial.println(n1 | n2,DEC);
  Serial.println(n1 | n2,BIN);
  
  Serial.println("Operador binário XOR ");
  Serial.println(n1 ^ n2,DEC);
  Serial.println(n1 ^ n2,BIN);
  
  Serial.println("Operador binário NOT ");
  Serial.println(n1,BIN );
  Serial.println(~n1,DEC );
  Serial.println(~n1,BIN );  
}

void loop(){ 

}
*/