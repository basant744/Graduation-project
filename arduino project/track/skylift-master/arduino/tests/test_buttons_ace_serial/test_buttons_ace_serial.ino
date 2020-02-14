

#include <ESP8266WiFi.h>
//#include "location.h"

char ssid[] ="maha";    // your network SSID (name) 
char pass[] = "ihaveaccess123";   // your network password
//
//// Google API key
//String geolocationKey = "AIzaSyA_JkHrZDEe-u9pO0SPehXRk8USAgjNY8E";
//String geocodingKey   = "AIzaSyDyJ-xjWB9TH4seMIyvRl-snRUwObr4ITE";


String key = "AIzaSyCtA_SpgsZKI2Gk4bjoC4qxABo6cJnAdNY";


double latitude    = 0.0;
double longitude   = 0.0;
double accuracy    = 0.0;
//
//// From http://www.mcc-mnc.com/
//int MCC = 602;  // Egypt Country Code
//int MNC = 2;    // Egypt Network Code
//String carrier = "Vodafone";
//
//Location myLocation;

// ===========================================================================================

void setup() {
//  Serial.begin(115200);  
//
//  // Set WiFi to station mode and disconnect from an AP if it was previously connected
//  WiFi.mode(WIFI_STA);
//  WiFi.disconnect();
//  delay(100);
//
//  WiFi.begin(ssid, pass);
//
//  while (WiFi.status() != WL_CONNECTED) {
//    delay(500);
//    Serial.print(".");        
//  }
//        
//  Serial.println("."); 
//  Serial.println("WiFi connected");
//  Serial.print("local IP: ");
//  Serial.println(WiFi.localIP());
//
//  // initialize the myLocation
//  myLocation.begin(geolocationKey, geocodingKey, MCC, MNC, carrier);
//    
  Serial.begin(9600);
  Serial.println("Start");
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
  Serial.println("Setup done");
}

// ===========================================================================================

void loop() {  
//  
//  myLocation.getLocation();
//
//  Serial.print("Latitude = ");     Serial.println(myLocation.latitude,7);
//  Serial.print("Longitude = ");    Serial.println(myLocation.longitude,7);
//  Serial.print("Accuracy = ");     Serial.println(myLocation.accuracy);
//  Serial.print("Address: ");       Serial.println(myLocation.address); 
//  Serial.println("-------------------------");
//
//  
//  // Wait for 1 Min.
//  delay(20000);      
//  

int n = WiFi.scanNetworks();
  Serial.println("scan done");
  if (n == 0)
    Serial.println("no networks found");
  else
  {
   Serial.print(n);
    Serial.println(" networks found...");

    if (more_text) {
      Serial.println("\"wifiAccessPoints\": [");
      for (int i = 0; i < n; ++i)
      {
        Serial.println("{");
        Serial.print("\"macAddress\" : \"");
        Serial.print(WiFi.BSSIDstr(i));
        Serial.println("\",");
        Serial.print("\"signalStrength\": ");
}

// ===========================================================================================
