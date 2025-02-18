int sensorPin = A0;    // select the input pin for the potentiometer
int ledPin = 13;      // select the pin for the LED
int sample = 0;  // variable to store the value coming from the sensor

void setup() {
  // declare the ledPin as an OUTPUT:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // read the value from the sensor:
  sample = analogRead(sensorPin);

  float voltage=(sample/1023.0)*5; //LDR voltage
  Serial.println("Sample:"+String(sample));
  Serial.println("Voltage:"+String(voltage));
  delay(1000);
}