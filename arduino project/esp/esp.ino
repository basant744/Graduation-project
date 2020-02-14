#include <SoftwareSerial.h>
#include <FirebaseESP8266.h>
#include <ESP8266WiFi.h>



#define WIFI_SSID "noha"
#define WIFI_PASSWORD "nohash12"



#define FIREBASE_HOST "https://graduation-project-e1f14.firebaseio.com/"
#define FIREBASE_AUTH "AS6HBsDRjJEk8Fnjayp6sw8l00CisuF0odQRO3co"

FirebaseData firebaseData;

//static const uint8_t D0   = 16;
//static const uint8_t D1   = 5;
static const uint8_t D2   = 4;
static const uint8_t D3   = 0;
//static const uint8_t D4   = 2;
//static const uint8_t D5   = 14;
//static const uint8_t D6   = 12;
//static const uint8_t D7   = 13;
//static const uint8_t D8   = 15;
//static const uint8_t D9   = 3;
//static const uint8_t D10  = 1; 
 
SoftwareSerial btSerial(D2, D3); // Rx,Tx
int led = D4;   // led also the internal led of NodemCU
int ledState = LOW;   // led state to toggle
String ledB = "";

unsigned long previousMillis = 0;  // millis instaed of delay
const long interval = 500;  // blink after ecery 500ms

void setup() {
  delay(1000);
  Serial.begin(9600);     
  btSerial.begin(9600);     // bluetooth module baudrate 
  pinMode(D4, OUTPUT);
  Serial.println("Started...");

    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    Serial.print("connecting");
    while (WiFi.status() != WL_CONNECTED) {
//    Serial.print(".");
    delay(500);
    Firebase.begin(FIREBASE_HOST,FIREBASE_AUTH);
  }
}

void loop() {

  if (btSerial.available() > 0) {    // check if bluetooth module sends some data to esp8266
    String data = btSerial.readString();  // read the data from HC-05
    for( int i = 0 ;i < data.length();i = i + 2) 
{
  if (String(data[0])== "T")
  {
   String D = String (data[i+2]) + String(data[i+3]);
   Serial.println(D);
   //Firebase.setString(firebaseData,"/heartrate",D);
   Firebase.setString(firebaseData,"/Temperature",D);

   delay(2500);
  }
  else if (String(data[0])== "E")
  {
    String D = String (data[i+2]) + String(data[i+3]);
   Serial.println(D);
   //Firebase.setString(firebaseData,"/heartrate",D);
   Firebase.setString(firebaseData,"/ECG",D);

   delay(2500);
  }
  else
  {
    String D = String (data[i+2]) + String(data[i+3]);
   Serial.println(D);
   Firebase.setString(firebaseData,"/heartrate",D);
 

   delay(2500);
  }
}
 
      //Serial.print(data);
//  switch (data)
//   {
//      case 'B':         // if receive data is 'B'
//        ledB = "blink"; 
//       
//
//        // write the string
//        break;
//      case 'S':              // if receive data is 'S'
//       ledB = "stop";
//
//        break;
//      default:
//        break;
//   }
//  }
//   unsigned long currentMillis = millis();
//  if (ledB == "blink") {          // if received data is 'B' the start blinking 
//    Serial.println("blinking started");
//    if (currentMillis - previousMillis >= interval) {
//     previousMillis = currentMillis;
//      if (ledState == LOW) {
//       ledState = HIGH;
//     } 
//     else {
//      ledState = LOW;
//     }
//
//    }
  
    
    
//   String text = Firebase.getString("message");
//   Serial.write(text); //or use serial.print
  // Serial.print(Firebase.getInt("message");
  }
}
