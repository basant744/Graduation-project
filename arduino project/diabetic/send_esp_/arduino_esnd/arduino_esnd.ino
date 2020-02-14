
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
// 
fsrReading2 = analogRead(fsrAnalogPin2);
m=String(fsrReading2);
strcat(v,m.c_str());
String k="m";
strcat(v,k.c_str());
Serial.write(v,10); 
delay(2000);

//  Serial.print("index");
//  Serial.print(v[0]);
//  
//  Serial.print("index");nohash123
//  Serial.print(v[1]);
//  Serial.print("index");
//  Serial.print(v[2]);
//  Serial.print("index");
//  Serial.print(v[3]);
//  Serial.print("index");
//  Serial.print(v[4]);
//  Serial.print("index");
//  Serial.print(v[5]);
//  Serial.print("index");
//  Serial.print(v[6]);
//    Serial.print("index");
//  Serial.print(v[7]);
//    Serial.print("index");
//  Serial.print(v[8]);
//    Serial.print("index");
//  Serial.println(v[9]);
//  delay(5000);

//Serial.write(c,5); 
//delay(800);
//memset(c, 0, sizeof(c)); //2ashan asafer el array



}
