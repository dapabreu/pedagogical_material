//Initializing LED Pin
int led1_R = 9;
int led1_G=10;
int led1_B=11;
char number='0';
int i;

void setup()
{
  pinMode(led1_R, OUTPUT);
  pinMode(led1_G, OUTPUT);
  pinMode(led1_B, OUTPUT);
  digitalWrite(led1_R, LOW);
  delay(100);
  digitalWrite(led1_R, HIGH);
  delay(100);
  digitalWrite(led1_G, LOW);
  delay(100);
  digitalWrite(led1_G, HIGH);
  delay(100);
  digitalWrite(led1_B, LOW);
  delay(100);
  digitalWrite(led1_B, HIGH);
  analogWrite(led1_R, 255);
  analogWrite(led1_G, 255);
  analogWrite(led1_B, 255);
}

void loop()
{
  switch(number)
  {
    case '0':
             for( i=250; i>0; (i=i-25))
            {
              analogWrite(led1_R, i);
              delay(3000);
            } 
            number='1';i=255;
            digitalWrite(led1_R, HIGH);
    break;
    case '1':
            for( i=250; i>0;(i=i-15))
          {
            analogWrite(led1_G, i);
            delay(3000);
          }
          number='2';i=255;
          digitalWrite(led1_G, HIGH);
    break;
    case '2':
            for( i=255; i>0;(i=i-15))
          {
            analogWrite(led1_B, i);
            delay(2000);
          }
          number='3';i=255;
          digitalWrite(led1_B, HIGH);
    break;
    case '3':
            for( i=255; i>0;(i=i-15))
          {
            analogWrite(led1_R, i);
            analogWrite(led1_B, i);
            delay(2000);
          }
          number='4';i=255;
          digitalWrite(led1_R, HIGH);
          digitalWrite(led1_B, HIGH);
          
    break;
    case '4':
            for( i=255; i>0;(i=i-15))
          {
            analogWrite(led1_G, i);
            analogWrite(led1_B, i);
            delay(2000);
          }
          number='5';i=255;
          digitalWrite(led1_G, HIGH);
          digitalWrite(led1_B, HIGH);
          
    break;
    case '5':
            for( i=255; i>0;(i=i-15))
          {
            analogWrite(led1_G, i);
            analogWrite(led1_B, i);
            delay(2000);
          }
          number='6';i=255;
          digitalWrite(led1_G, HIGH);
          digitalWrite(led1_B, HIGH);
          
    break;
    case '6':
          digitalWrite(led1_R, LOW);
          delay(1000);
          digitalWrite(led1_R, HIGH);
          digitalWrite(led1_G, LOW);
          delay(1000);
          digitalWrite(led1_G, HIGH);
           digitalWrite(led1_B, LOW);
          delay(1000);
          digitalWrite(led1_B, HIGH);
          number='0';i=255;
          delay(5000);
    break;
    default:
    break;
  } 
}
