#include <OneWire.h>
#include <DallasTemperature.h>
#include <SimpleModbusMaster.h>

#define slaveAddr 1
#define baud 9600
#define timeout 1000
#define polling 1
#define retry_count 0
#define TxEnablePin 2 
enum
{
  PACKET1,
  TOTAL_NO_OF_PACKETS
};

Packet packets[TOTAL_NO_OF_PACKETS];
packetPointer packet1 = &packets[PACKET1];
unsigned int writeRegs[3];

//Red cable to +5V and Black/Grey cable to GND
//Yellow/Blue Cable is plugged into D3/Pin 3 on Arduino Proto Screw
#define One_Wire_Pin 3

//Thermometer resolution is programmable from 9 to 12 bits
#define Thermometer1_Resolution 9
#define Thermometer2_Resolution 9

//Setup a one wire communication
OneWire One_Wire(One_Wire_Pin);

//Pass our oneWire reference to Dallas Temperature. 
DallasTemperature Temperature_Sensor(&One_Wire);

//Setup Temperature Sensor Address
DeviceAddress Temperature_Sensor1_Address = {0x28, 0xFF, 0x12, 0x77, 0x52, 0x15, 0x01, 0xE0};
DeviceAddress Temperature_Sensor2_Address = {0x28, 0xFF, 0xCB, 0x29, 0x15, 0x15, 0x01, 0xCB};


void setup(void)
{
//Modbus Slave Setup  
 modbus_construct(packet1, slaveAddr, PRESET_MULTIPLE_REGISTERS, 0, 3, writeRegs);
 modbus_configure(&Serial, baud, SERIAL_8E1, timeout, polling, retry_count, TxEnablePin, packets, TOTAL_NO_OF_PACKETS);  


//Temperature Sensor Setup
  Temperature_Sensor.begin();
 Temperature_Sensor.setResolution(Temperature_Sensor1_Address, Thermometer1_Resolution);
 Temperature_Sensor.setResolution(Temperature_Sensor2_Address, Thermometer2_Resolution);
  
  if(!Temperature_Sensor.getResolution(Temperature_Sensor1_Address) ||
     !Temperature_Sensor.getResolution(Temperature_Sensor2_Address))
  {
    //Get Temperature Sensor Address
    int numberOfDevices = Temperature_Sensor.getDeviceCount();
    Serial.print("Locating devices...");  
    Serial.print("Found ");
    Serial.print(numberOfDevices, DEC);
    Serial.println(" devices.");       
    if(numberOfDevices>0)Serial.println("Please Setup Address with : ");
    DeviceAddress tempDeviceAddress;
    for(int i=0;i<numberOfDevices; i++)
    {
      if(Temperature_Sensor.getAddress(tempDeviceAddress, i))
    {      
      Serial.print("DeviceAddress Temperature_Sensor");
      Serial.print(i+1, DEC);
      Serial.print("_Address = ");
      printAddress(tempDeviceAddress);
      Serial.println();
      
    }else{
      Serial.print("Found ghost device at ");
      Serial.print(i, DEC);
      Serial.println(" but could not detect address. Check power and cabling");
    }
    }
    while(1){};
  }

}


void loop(void)
{ 
 Temperature_Sensor.requestTemperatures(); 
 //Resolution=9 delay time 94ms per sensor
 //Resolution=10 delay time 188ms per sensor
 //Resolution=11 delay time 375ms per sensor
 //Resolution=12 delay time 750ms per sensor
 //Error -127.00
 float Temperature1_Celsius = 100 * Temperature_Sensor.getTempC(Temperature_Sensor1_Address);
 float Temperature2_Celsius = 100 * Temperature_Sensor.getTempC(Temperature_Sensor2_Address);  
 writeRegs[0]=(word)random(1000);
 writeRegs[1]=(word)Temperature1_Celsius;  
 writeRegs[2]=(word)Temperature2_Celsius; 
 modbus_update();
}


void printAddress(DeviceAddress deviceAddress)
{
  Serial.print("{");
  for (uint8_t i = 0; i < 8; i++)
  {
    Serial.print("0x");
    if (deviceAddress[i] < 16) Serial.print("0");
    Serial.print(deviceAddress[i], HEX);
    if(i<7)Serial.print(", ");
  }
  Serial.print("};");
}
