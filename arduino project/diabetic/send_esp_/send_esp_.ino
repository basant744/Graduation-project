#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>

#define FIREBASE_HOST "https://graduation-project-e1f14.firebaseio.com/" 
#define FIREBASE_AUTH "AS6HBsDRjJEk8Fnjayp6sw8l00CisuF0odQRO3co" 
#define WIFI_SSID "noha"
#define WIFI_PASSWORD "nohash123"
FirebaseData firebaseData;


char mystr[20];
char firstread[8];
char secondread[8];//Initialized variable to store recieved dopata
String p1;
String p2;

String x;
String y;

void setup() {
  // Begin the Serial at 9600 Baud
  Serial.begin(9600);
   WiFi.begin(WIFI_SSID, WIFI_PASSWORD); 
 Serial.print("connecting"); 
 while (WiFi.status() != WL_CONNECTED) { 
   Serial.print("."); 
   delay(500);
    Serial.println(); 
 Serial.print("connected: "); 
 Serial.println(WiFi.localIP()); 
 Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}
}

void loop() {
    memset(mystr, 0, sizeof(mystr));
  
Serial.readBytes(mystr,10);//Read the serial data and store in var    
  Serial.println(mystr);
 // delay(100);

//  
y="";
for(int i=0; i<= 10 ;i++)
{
  char inChar = (char)mystr[i];
    x= inChar;

    if(x== "p"  || x== "m")
     {
      Serial.println(y);
      if(x=="p")
      {
      Firebase.setString(firebaseData,"/firstpressure:",y);
      y="";

      }
      else
      {
       Firebase.setString(firebaseData,"/secondpressure:",y);
       y="";
      }
      continue;
      
     }
    
     else 
     {
       y+=inChar;
     }
  
}
}



    

   
