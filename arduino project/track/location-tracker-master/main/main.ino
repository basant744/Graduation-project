//
//  thinspeak-location.ino
//  Created by Ezequiel França on 11/09/18.
//

#include <WifiLocation.h>
#ifdef ARDUINO_ARCH_SAMD
#include <WiFi101.h>
#elif defined ARDUINO_ARCH_ESP8266
#include <ESP8266WiFi.h>
#elif defined ARDUINO_ARCH_ESP32
#include <WiFi.h>
#else
#error Wrong platform
#endif

// Google Settings
const char *GOOGLE_API_KEY = "AIzaSyCtA_SpgsZKI2Gk4bjoC4qxABo6cJnAdNY";

// Wifi Settings
const char *SSID = "maha";
const char *PASSWD = "ihaveaccess123";

WiFiClient client;
WifiLocation location(GOOGLE_API_KEY);

// ThingSpeak Settings
unsigned long CHANNEL_ID = 977794;
String WRITE_API_KEY = "DG4BW9AP8EKXEKSI"; // write API key for your ThingSpeak Channel
const char *SERVER = "api.thingspeak.com";
const int postingInterval = 20 * 1000; // post data every 20 seconds

void setup()
{
  Serial.begin(115200);
  
    // Connect to WPA/WPA2 network
#ifdef ARDUINO_ARCH_ESP32
    WiFi.mode(WIFI_MODE_STA);
#endif
#ifdef ARDUINO_ARCH_ESP8266
    WiFi.mode(WIFI_STA);
#endif
    WiFi.begin(SSID, PASSWD);
    while (WiFi.status() != WL_CONNECTED)
    {
        Serial.print("Attempting to connect to WPA SSID: ");
        Serial.println(SSID);
        Serial.print("Status = ");
        Serial.println(WiFi.status());
        delay(500);
    }
}

void request(String body) {
  
    if (client.connect(SERVER, 80))
    {
        client.println("GET /update HTTP/1.1");
        client.println("Host: api.thingspeak.com");
        client.println("User-Agent: ESP8266 (nothans)/1.0");
        client.println("Connection: close");
        client.println("X-THINGSPEAKAPIKEY: " + WRITE_API_KEY);
        client.println("Content-Type: application/x-www-form-urlencoded");
        client.println("Content-Length: " + String(body.length()));
        client.println("");
        client.print(body);
    }
    client.stop();
}


void loop()
{
    location_t loc = location.getGeoFromWiFi();
        
    Serial.println("Latitude: " + String(loc.lat, 7));
    Serial.println("Longitude: " + String(loc.lon, 7));

    String body = "longitude=" + String(loc.lon, 7) + "&" + "latitude=" + String(loc.lat, 7) + "&" + "field1=" + String(loc.lon, 7) + "&" + "field2=" + String(loc.lat, 7);
    request(body);
    
    delay(postingInterval);
}
