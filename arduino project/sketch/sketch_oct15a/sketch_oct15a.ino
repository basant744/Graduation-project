//Program for simple counter
#include <SoftwareSerial.h>
#include <FirebaseESP8266.h>
#include <ESP8266WiFi.h>

#define WIFI_SSID "noha"
#define WIFI_PASSWORD "nohash123"



#define FIREBASE_HOST "https://graduation-project-e1f14.firebaseio.com/"
#define FIREBASE_AUTH "AS6HBsDRjJEk8Fnjayp6sw8l00CisuF0odQRO3co"

FirebaseData firebaseData;
const int analogInPin = A0;  // ESP8266 Analog Pin ADC0 = A0
int fsrReading;

//String  mystring="545";
//String   me;



void setup() {
  Serial.begin(115200);
   
 
  // connect to wifi. 
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD); 
  Serial.print("connecting"); 
  while (WiFi.status() != WL_CONNECTED) { 
    Serial.print("."); 
    delay(500); 
  } 
  Serial.println(); 
  Serial.print("connected: "); 
  Serial.println(WiFi.localIP()); 
   
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH); 
}
void loop() {
   fsrReading  = analogRead(analogInPin);


 Serial.print("Analog reading = ");
  Serial.println(fsrReading);
   String me = String(fsrReading);
   
  Firebase.setString(firebaseData,"/pressure",me );


  delay(1000);

  // me=Serial.read();
 
 
  
}
//static const uint8_t D0   = 16;
//static const uint8_t D1   = 5;
//static const uint8_t D2   = 4;
//static const uint8_t D3   = 0;
//static const uint8_t D4   = 2;
//static const uint8_t D5   = 14;
//static const uint8_t D6   = 12;
//static const uint8_t D7   = 13;
//static const uint8_t D8   = 15;
//static const uint8_t D9   = 3;
//static const uint8_t D10  = 1; 
 
//SoftwareSerial btSerial(D2, D3); // Rx,Tx

//     Firebase.setInt(firebaseData,"/signals",data);

//  Serial.print(str);
   // String thisString = String(str);
    
  // Serial.print("fgf"); 
    //Firebase.setString(firebaseData,"/pressure",me );
