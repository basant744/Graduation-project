#include <SoftwareSerial.h>
SoftwareSerial btSerial(0, 3);
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600); 
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println("tfvfv");
delay(1000);
}
