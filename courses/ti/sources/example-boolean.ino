bool A, B, C;
int a=12,b=12,c=13;

void setup(){
  Serial.begin(9600);
  Serial.println(a);

  A=true;
  B=false;

  Serial.println(!A);

  C=A && B;
  Serial.println(C);

  C=A || B;
  Serial.println(C);

  C=A && !B;
  Serial.println(C);

  C=(a==b);
  Serial.println(C);

  C=(a>c);
  Serial.println(C);     
}

void loop(){ }
