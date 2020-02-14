int fsrAnalogPin = 0; // FSR is connected to analog 0
int LEDpin = 11;      // connect Red LED to pin 11 (PWM pin)
int fsrReading;      // the analog reading from the FSR resistor divider
int LEDbrightness;
 
void setup(void) {
  Serial.begin(9600);   // We'll send debugging information via the Serial monitor
  pinMode(LEDpin, OUTPUT);
}
 
void loop(void) {
  fsrReading = analogRead(fsrAnalogPin);
  Serial.print("Analog reading = ");
  Serial.println(fsrReading);
 
  // we'll need to change the range from the analog reading (0-1023) down to the range
  // used by analogWrite (0-255) with map!
  LEDbrightness = map(fsrReading, 0, 1023, 0, 255);
  // LED gets brighter the harder you press
  analogWrite(LEDpin, LEDbrightness);
 
  delay(100);
}



   ////void setup() {
////    Serial.begin(9600);
////}
//// 
////void loop(){
////int sensorVal=analogRead(A1);
////Serial.print("Sensor Value: ");
////Serial.print(sensorVal);
////
////float voltage = (sensorVal*5.0)/1024.0;
////    Serial.print("Volts: ");
////    Serial.print(voltage);
////   
////  float pressure_pascal = (3.0*((float)voltage-0.47))*1000000.0;
////  float pressure_bar = pressure_pascal/10e5;
////    Serial.print("Pressure = ");
////    Serial.print(pressure_bar);
////    Serial.println(" bars");
////    Serial.print("Pressure = ");
////   
////    delay(100);
////}
//
///* FSR testing sketch.
