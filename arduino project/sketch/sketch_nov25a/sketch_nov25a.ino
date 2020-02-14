const int analogInPin = A0;  // ESP8266 Analog Pin ADC0 = A0
int fsrReading;


void setup() {
  // initialize serial communication at 115200
  Serial.begin(115200);
}

void loop() {
  // read the analog in value
  fsrReading  = analogRead(analogInPin);


 Serial.print("Analog reading = ");
  Serial.println(fsrReading);
   
   
  


  delay(1000);
}
