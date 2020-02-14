
String m;
char c[2];

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

fsrReading = analogRead(fsrAnalogPin);
z=String(fsrReading);
strcat(v,z.c_str());
Serial.write(v,5); 
delay(800);



//m=String(x);
//strcat(c,m.c_str());
//Serial.write(c,2);   
//delay(100);
}





















//
//#include <OneWire.h>
//#include <DallasTemperature.h>
//
//#define ONE_WIRE_BUS 4
//
//OneWire oneWire(ONE_WIRE_BUS);
//
//DallasTemperature sensors(&oneWire);
//
// int Celcius=0;
//String m; //temperature
//char t[3];
//
//char p[4];
//String z; //pressure
//
//int fsrAnalogPin = 0;
//int fsrReading;
//
//void setup() {
//  // Begin the Serial at 9600 Baud
//  Serial.begin(9600);
//}
//
//void loop() {
//memset(p, 0, sizeof(p));
//memset(t, 0, sizeof(t));
//
//fsrReading = analogRead(fsrAnalogPin);
//z=String(fsrReading);
////Serial.print("z=");
////Serial.println(z);
//strcat(p,z.c_str());
////Serial.print("p=");
////Serial.println(p);
//Serial.write(p,4); 
//delay(1000);
// //2ashan asafer el array
//
////Serial.println("");
// sensors.requestTemperatures(); 
//  Celcius=sensors.getTempCByIndex(0);
//  m=String(Celcius);
//  strcat(t,m.c_str());
//  Serial.write(t,2);  
//  //  Serial.print(Celcius);
//    delay(1000);
//    Serial.println("");
//
//
//}
