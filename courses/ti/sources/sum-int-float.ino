int a=10,b=5,divide=0,resto,soma,c=10,f=3;
float d=15.33, e;

void setup(){
  Serial.begin(9600);

  a=a+1;
  Serial.println(a);

  divide=a/b;
  Serial.println(divide);
  
  resto=a%b;
  Serial.println(resto);

  e=d+a;
  Serial.println(e);

  soma=a+d;
  Serial.println(soma);
}

void loop(){ }
