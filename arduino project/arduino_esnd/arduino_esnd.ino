#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 4

OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);

 int Celcius=0;
String m;
char c[4];

char v[4];
String z;

int fsrAnalogPin = 0;
int fsrReading;

void setup() {
  // Begin the Serial at 9600 Baud
  Serial.begin(9600);
}

void loop() {

memset(v, 0, sizeof(v)); //2ashan asafer el array
memset(c, 0, sizeof(c)); //2ashan asafer el array

fsrReading = analogRead(fsrAnalogPin);
z=String(fsrReading);
strcat(v,z.c_str());
Serial.write(v,5); 
delay(1000);


 sensors.requestTemperatures(); 
 Celcius=sensors.getTempCByIndex(0);
m=String(Celcius);
strcat(c,m.c_str());
Serial.write(c,3);   
delay(1000);
}
