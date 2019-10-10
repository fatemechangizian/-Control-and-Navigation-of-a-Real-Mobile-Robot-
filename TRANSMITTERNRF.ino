#include <nRF24L01.h>
#include <printf.h>
#include <RF24.h>
#include <RF24_config.h>

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 2

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

RF24 radio(5, 10);
const uint64_t pipe = 0xE8E8F0F0E1LL;
float temp;
int tempPin = 1;

void setup(void) {
Serial.begin(9600);
sensors.begin();
radio.begin();
radio.openWritingPipe(pipe);
}

void loop(void)
{
 float temp = analogRead(tempPin);
 // read analog volt from sensor and save to variable temp
 temp = temp * 0.1074;
 // convert the analog volt to its temperature equivalent

radio.write(&temp, sizeof(float));
delay(1000);
}
