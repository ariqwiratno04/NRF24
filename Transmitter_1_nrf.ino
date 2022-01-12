#include <RF24Network.h>
#include <RF24.h>
#include <SPI.h>

RF24 radio(4, 10);               // nRF24L01 (CE,CSN)
RF24Network network(radio);

const uint16_t this_node = 01;
const uint16_t master = 00;

//const uint64_t pipe = 0xE8E8F0F0E1LL

float Data[6];


void setup() {
  Serial.begin(9600);
  SPI.begin();
  radio.begin();
  network.begin(90, this_node);
  radio.setDataRate(RF24_2MBPS);
  //radio.openWritingPipe(pipe);
}

void loop() {

  Data[0] = 01;
  network.update();

  RF24NetworkHeader header7(master);
  bool ok = network.write(header7, &Data, sizeof(Data));

//radio.write(Data, sizeof(Data));

}
