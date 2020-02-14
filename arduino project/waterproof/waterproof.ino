#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 4

OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);

// float Celcius=0;
int Celcius=0;
 //float Fahrenheit=0;
void setup(void)
{
  
  Serial.begin(9600);
  sensors.begin();
   if(!sensors.isParasitePowerMode())Serial.print("NOT ");
  Serial.println("parasite powered");
}

void loop(void)
{ 
  sensors.requestTemperatures(); 
  Celcius=sensors.getTempCByIndex(0);
 // Fahrenheit=sensors.toFahrenheit(Celcius);
 // Serial.print(" C  ");
  Serial.println(Celcius);
//  Serial.print(" F  ");
//  Serial.println(Fahrenheit);
  delay(1000);
}
