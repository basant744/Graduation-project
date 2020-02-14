#include <SoftwareSerial.h>
SoftwareSerial hc06(2,3);

char appData;  
String inData = "";
void setup(){
  //Initialize Serial Monitor
  Serial.begin(9600);
  Serial.println("ENTER AT Commands:");
  //Initialize Bluetooth Serial Port
  hc06.begin(9600);
}

void loop(){
  //Write data from HC06 to Serial Monitor



 if (hc06.available()){
  hc06.write("hbvvjk");
    appData = hc06.read();
    inData = String(appData);
      Serial.println(inData);
    //Serial.println(hc06.read());
  //}
  
  //Write from Serial Monitor to HC06
  //if (Serial.available()){
    //hc06.write(Serial.read());
  } 
} 
 
