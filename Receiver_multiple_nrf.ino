#include <RF24Network.h>
#include <RF24.h>
#include <SPI.h>

RF24 radio(22, 21);               // nRF24L01 (CE,CSN)
RF24Network network(radio);

//const uint64_t pipe = 0xE8E8F0F0E1LL;

const uint16_t this_node = 00;
float Data[6];


float Data1;
float Data2;

void setup() {
  Serial.begin(9600);
  SPI.begin();
  radio.begin();
//  radio.openReadingPipe(1, pipe);
//  radio.startListening;
  network.begin(90, this_node);
  radio.setDataRate(RF24_2MBPS);
}

void loop() {
 
  network.update();
  
  while(network.available()){
    
  Serial.println("Connect");
  //radio.read(Data, sizeof(Data));
  RF24NetworkHeader header;
  network.read(header, &Data, sizeof(Data));

  if(header.from_node == 1){
    Data1 = Data[0];
    Serial.println(Data1);
  }
  if(header.from_node == 2){
    Data2 = Data[0];
    Serial.println(Data2);
  }
//  Serial.print("Data 1 :");
//  Serial.println(Data[0]);
//  Serial.print("Data 2 :");
//  Serial.println(Data2);

  delay(500);
  }

  
}
