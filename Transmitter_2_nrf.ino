#include <RF24Network.h>
#include <RF24.h>
#include <SPI.h>

RF24 radio(7, 8);               // nRF24L01 (CE,CSN)
RF24Network network(radio);

const uint16_t this_node = 02;
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

  Data[0] = 02;
  network.update();
  RF24NetworkHeader header8(master);
  bool ok = network.write(header8, &Data, sizeof(Data));
  //radio.write(Data, sizeof(Data));
  Serial.println(Data[0]);
}
