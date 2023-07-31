
#include "DHT22 Driver.h"
#include <Arduino.h>


#define DHT_PIN 5


static DHT22_Driver myDHT22;


float temperature = 0.0;
float    humidity = 0.0;


void setup()
{
	Serial.begin(9600);
	myDHT22.begin(DHT_PIN);
	while (!Serial);
}


void loop()
{
	delay(2000);

	myDHT22.read();

	temperature = myDHT22.getTemperature();
	   humidity = myDHT22.getHumidity();

	Serial.print("Temperature: ");
	Serial.println(temperature);

	Serial.print("Humidity: ");
	Serial.println(humidity);
}



