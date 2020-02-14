
String m;
//char c[4];

char v[10];
String z;

int fsrAnalogPin = 0;
int fsrReading;

int fsrAnalogPin2 = 2;
int fsrReading2;

void setup() {
  // Begin the Serial at 9600 Baud
  Serial.begin(9600);
}

void loop() {

memset(v, 0, sizeof(v)); 

fsrReading = analogRead(fsrAnalogPin);
z=String(fsrReading);
strcat(v,z.c_str());
String x="p";
strcat(v,x.c_str());

 //2ashan asafer el array
fsrReading2 = analogRead(fsrAnalogPin2);
m=String(fsrReading2);
strcat(v,m.c_str());
String k="m";
strcat(v,k.c_str());
Serial.write(v,10); 
delay(1000);


}
