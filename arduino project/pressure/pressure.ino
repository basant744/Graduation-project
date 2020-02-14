
int fsrAnalogPin = 0;
int fsrReading;
void setup() {
    Serial.begin(9600);
}
 
void loop(){
fsrReading = analogRead(fsrAnalogPin);
 Serial.print("Analog reading = ");
  Serial.println(fsrReading);
   
    delay(100);
}
