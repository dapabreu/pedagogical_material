String myName="bananablaster9000";
String mySentence = " o super-heroi";  //NOTEM AS ASPAS !!!
char a='A';                            //NOTEM AS PLICAS !!

void setup(){
  Serial.begin(9600);
  Serial.println(a);
  Serial.println("O nome:"+myName);
  Serial.println(myName+mySentence);    //Exemplo de concatenação
}


void loop(){ }
