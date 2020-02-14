#include <SoftwareSerial.h>
#include <SPI.h>
#include <MFRC522.h>
SoftwareSerial HM10(2, 3); // RX = 2, TX = 1
char appData;  
String inData = "";
# define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN); 
int serNum0=0;
int serNum1=0;
int serNum2=0;
int serNum3=0;
char t;
int z =0;
int zz  =0;

const int trigPin = 4;
const int echoPin = 5;
// defines variables
long duration;
int distance;


#define IN1 A0
#define IN2 A1
#define IN3 A2
#define IN4 A3
#define SPEED 6







int x =5 ;

void setup()
{
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9100);
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  Serial.println("HM10 serial started at 9100");
  HM10.begin(9100); // set HM10 serial at 9100 baud rate



   pinMode(IN1, OUTPUT);
   pinMode(IN2, OUTPUT);
   pinMode(IN3, OUTPUT);
   pinMode(IN4, OUTPUT);
   pinMode(SPEED, OUTPUT);
   
    
   digitalWrite(IN1, LOW);
   digitalWrite(IN2, LOW);
   digitalWrite(IN3, LOW);
   digitalWrite(IN4, LOW);
   analogWrite(SPEED, 0);
   



  //Serial.println();




}

void loop()
{

   // Serial.println(ultrasoundaver());


   Serial.println (inData);
  
   /* if (ultrasoundaver()<20){
              upright();
              delay(300);
              forward();
              delay(700);
              upleft();
              delay(200);
              forward();
              delay(500);
              upleft();
              delay(300);
              forward();
              delay(700);
              upright();
              delay(300);
              forward();
              delay (1000);
              sttop();
    }
    else {      
      */
    appData = HM10.read();
    inData = String(appData);  // save the data in string format
       if (inData=="s")//stop
      {
        sttop();
       }
      else if (inData=="f")//up
      {

 forward();

        }

        else if (inData=="d") //down
        {
   digitalWrite(IN1, HIGH);
   digitalWrite(IN2, LOW);
   digitalWrite(IN3, HIGH);
   digitalWrite(IN4, LOW);
   analogWrite(SPEED, 80);

      Serial.println (inData);

   
        }

        else if (inData=="R") //right/up
        {

   upright();  
        }
        else if (inData=="L") //left/up
        {


       upleft();
 
        }
        else if (inData=="r") //down/right
        {
   digitalWrite(IN1, HIGH);
   digitalWrite(IN2, LOW);
   digitalWrite(IN3, LOW);
   digitalWrite(IN4, LOW);
   analogWrite(SPEED, 70);
       Serial.println (inData);

        }
        else if (inData=="l") //left/down
        {
   digitalWrite(IN1, LOW);
   digitalWrite(IN2, LOW);
   digitalWrite(IN3, HIGH);
   digitalWrite(IN4, LOW);
   analogWrite(SPEED, 70);
       Serial.println (inData);
        }
  
    }
 

void sttop(){
     digitalWrite(IN1, LOW);
   digitalWrite(IN2, LOW);
   digitalWrite(IN3, LOW);
   digitalWrite(IN4, LOW);
   analogWrite(SPEED, 0);
 
       if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards,;mmmmmmm'',m
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
  Serial.println();
  Serial.print(" UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  content.toUpperCase();
  Serial.println();

  
if (content.substring(1) == "8B 5A 02 C5"){
  HM10.write("8B 5A 02 C5");
  z=1;
}
else if (content.substring(1) == "86 DC 15 7E" ){
    HM10.write("86 DC 15 7E");

  zz=1;
}

  
}
   

int ulrtasound (){
  
  digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
//Serial.print("Distance: ");
//Serial.println(distance);
return distance;
  }
  double ultrasoundaver(){
     int readings=0;
     for (int i=0 ; i < 5 ; i++ ){
      readings=readings+ulrtasound();
      delay (10);
      }
      return (readings/5);
   
  }

  void forward(){

     digitalWrite(IN1, LOW);
   digitalWrite(IN2, HIGH);
   digitalWrite(IN3, LOW);
   digitalWrite(IN4, HIGH);
   analogWrite(SPEED, 80);

       Serial.println (inData);
  }
  void upright(){
      digitalWrite(IN1, LOW);
   digitalWrite(IN2, HIGH);
   digitalWrite(IN3, HIGH);
   digitalWrite(IN4, LOW);
   analogWrite(SPEED, 70);
       Serial.println (inData);  
  }

  void upleft(){
     digitalWrite(IN1, HIGH);
   digitalWrite(IN2, LOW);
   digitalWrite(IN3, LOW);
   digitalWrite(IN4, HIGH);
   analogWrite(SPEED, 70);
       Serial.println (inData);
  }

  void uppleft(){
    upleft();
    delay (60);
    //sttop();
    }


  void uppright(){
       upright();
    delay (60);
    sttop(); 
    
    }
