#define AxisX 0
#define AxisY 1

unsigned long ellapsed;
int maxX, maxY, minX, minY;

void setup() {
  Serial.begin(9600);
  ellapsed = millis();

  calibracao(1000);
}

void loop() {
  if (millis() - ellapsed > 100) {
    Serial.println("X:" + String(readX(minX, maxX)));
    Serial.println("Y:" + String(readY(minY, maxY)));
    ellapsed = millis();
  }
}

/*
* Calibra o joystick
*/
void calibracao(int tempoCalibracao) {
  maxX = 0;
  minX = 1023;
  maxY = 0;
  minY = 1023;
  
  unsigned long timeIni= millis();

  while (millis() - timeIni < tempoCalibracao){
    int X = analogRead(AxisX);
    int Y = analogRead(AxisY);
    if (X > maxX) maxX = X;
    if (X < minX) minX = X;
    if (Y > maxY) maxY = Y;
    if (Y < minY) minY = Y;
  }
  Serial.println("Concluida a calibracao");
  Serial.println("minX:" + String(minX) + " maxX:"+String(maxX) + " minY:"+String(minY)+ " maxY:"+String(maxY));
  delay(5000);   

}

int readX(int minX, int maxX) {
  int X = analogRead(AxisX);

  if ((X < minX) || (X > maxX))
    return (X - 512);
  return 0;
}

int readY(int minY, int maxY) {
  int Y = analogRead(AxisY);

  if ((Y < minY) || (Y > maxY))
    return (Y - 512);
  return 0;
}