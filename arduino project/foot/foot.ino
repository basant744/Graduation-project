#include <SoftwareSerial.h>

SoftwareSerial hc06(2,3);
int fsrAnalogPin = 0;
int fsrReading;

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
  hc06.begin(9600);
}

void loop() {
  
  // put your main code here, to run repeatedly:
fsrReading = analogRead(fsrAnalogPin);
 Serial.print("Analog reading = ");
  Serial.println(fsrReading);
   hc06.print("Analog reading = ");
      hc06.print(fsrReading);
  delay(800);
  
  if (hc06.available()){

   
    Serial.write(hc06.read());
  }
  
 
  
}
