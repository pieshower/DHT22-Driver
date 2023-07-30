
#include "DHT22 Driver.h"
#include <Arduino.h>



void setup()
{
	Serial.begin(9600);
	myDHT22.begin();
	while (!Serial);
}

void loop()
{
	delay(2000);
	myDHT22.read();
	myDHT22.print();
}

