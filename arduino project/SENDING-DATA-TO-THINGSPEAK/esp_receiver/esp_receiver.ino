//#include <ESP8266WiFi.h>
//#include "location.h"
//char ssid[] ="maha";    // your network SSID (name) 
//char pass[] = "ihaveaccess123";   // your network password
//
//// Google API key
//String geolocationKey = "AIzaSyA8I5-qvtRADriVB8RiA486YHvWYk9uELc";
//String geocodingKey   = "AIzaSyA8I5-qvtRADriVB8RiA486YHvWYk9uELc";
//
//// From http://www.mcc-mnc.com/
//int MCC = 602;  // Egypt Country Code
//int MNC = 3;    // Egypt Network Code
//String carrier = "  ETISALAT ";
//
////Location myLocation;
//
//
//void setup() {
//  // Begin the Serial at 9600 Baud
//  Serial.begin(9600);
//    WiFi.begin(ssid, pass);
// Serial.print("connecting"); 
// while (WiFi.status() != WL_CONNECTED) { 
//   Serial.print("."); 
//   delay(500);
//    Serial.println(); 
// Serial.print("connected: "); 
// Serial.println(WiFi.localIP()); 
//
//}
//}
//
//void loop() {
//
// 
//  
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
////#include <ESP8266WiFi.h>
////#include <FirebaseESP8266.h>
////
////#define FIREBASE_HOST "https://graduation-project-e1f14.firebaseio.com/" 
////#define FIREBASE_AUTH "AS6HBsDRjJEk8Fnjayp6sw8l00CisuF0odQRO3co" 
////#define WIFI_SSID "noha"
////#define WIFI_PASSWORD "nohash123"
////FirebaseData firebaseData;
////
////
////char mystr[20];
////char firstread[8];
////char secondread[8];//Initialized variable to store recieved data
////String p1;
////String p2;
////
////void setup() {
////  // Begin the Serial at 9600 Baud
////  Serial.begin(9600);
////   WiFi.begin(WIFI_SSID, WIFI_PASSWORD); 
//// Serial.print("connecting"); 
//// while (WiFi.status() != WL_CONNECTED) { 
////   Serial.print("."); 
////   delay(500);
////    Serial.println(); 
//// Serial.print("connected: "); 
//// Serial.println(WiFi.localIP()); 
//// Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
////}
////}
////
////void loop() {
////  
////  Serial.readBytes(mystr,10);//Read the serial data and store in var   
//// firstread[0] = mystr[0];
//// firstread[1] = mystr[1];
////firstread[2] = mystr[2];
//// firstread[3] = mystr[3];
//// firstread[4] = mystr[4];
//// //firstread[5] = mystr[5];
//// //firstread[6] = mystr[6];
//// p1 = firstread;
//// // Serial.println(mystr);
////  Serial.println( firstread);
////// Firebase.setString(firebaseData,"/pressure",p1);
////   delay(200);
////  
////// secondread[0]=mystr[3];
////// secondread[1]=mystr[4];
//////  p2=secondread;
////  
////  
//// //Serial.println(p2); //Print data on Serial Monitor
//////    Firebase.setString(firebaseData,"/mostafa2",p2);
////
////  
////}








// ====================================================================================
// Title  :  location 
// Author :  Eng. Mohamed Sayed Yousef  -  Mansoura, Egypt
//            https://electronics010.blogspot.com.eg/
// Date   :  25/02/2018
// ver    :  1.0
// Board  :  NodeMCU 1.0 
// ====================================================================================

// Libraries
#include <ESP8266WiFi.h>
#include "location.h"

char ssid[] ="xxxxxxxx";    // your network SSID (name) 
char pass[] = "xxxxxxxx";   // your network password

// Google API key
String geolocationKey = "xxxxxxxx";
String geocodingKey   = "xxxxxxxx";

// From http://www.mcc-mnc.com/
int MCC = 602;  // Egypt Country Code
int MNC = 2;    // Egypt Network Code
String carrier = "Vodafone";

Location myLocation;

// ===========================================================================================

void setup() {
  Serial.begin(115200);  

  // Set WiFi to station mode and disconnect from an AP if it was previously connected
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);

  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");        
  }
        
  Serial.println("."); 
  Serial.println("WiFi connected");
  Serial.print("local IP: ");
  Serial.println(WiFi.localIP());

  // initialize the myLocation
  myLocation.begin(geolocationKey, geocodingKey, MCC, MNC, carrier);
    
}

// ===========================================================================================

void loop() {  
  
  myLocation.getLocation();

  Serial.print("Latitude = ");     Serial.println(myLocation.latitude,7);
  Serial.print("Longitude = ");    Serial.println(myLocation.longitude,7);
  Serial.print("Accuracy = ");     Serial.println(myLocation.accuracy);
  Serial.print("Address: ");       Serial.println(myLocation.address); 
  Serial.println("-------------------------");

  
  // Wait for 1 Min.
  delay(60000);      
  
}

// ===========================================================================================
