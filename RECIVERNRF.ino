#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(5, 10);
const uint64_t pipe = 0xE8E8F0F0E1LL;
float temp;

void setup(void) {
Serial.begin(9600);
radio.begin();
radio.openReadingPipe(1, pipe);
radio.startListening();
Serial.begin(9600);
Serial.println("Temperature Starting.....");
delay(1000);
}

void loop(void)
{
if (radio.available()) {


Serial.print("Temperature : ");
Serial.println(temp);
delay(1000);
}
}
