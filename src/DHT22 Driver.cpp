
#include "DHT22 Driver.h"
#include <Arduino.h>




void DHT22_Driver::begin(int pin)
{
    _DHT22_.pin = pin;
    pinMode(_DHT22_.pin, INPUT_PULLUP);
    digitalWrite(_DHT22_.pin, HIGH);
}


bool DHT22_Driver::read()
{
    // Start send signal
    pinMode(_DHT22_.pin, OUTPUT);
    digitalWrite(_DHT22_.pin,  LOW);
    delay(5);
    digitalWrite(_DHT22_.pin, HIGH);
    delayMicroseconds(40);
    pinMode(_DHT22_.pin, INPUT);

    // DHT22 will pull low so we
    // need to wait for DHT22 to pull HIGH
    while (!digitalRead(_DHT22_.pin));

    // Parse through the 40 bits sent
    for (uint8_t i = 0; i < 40; i++)
    {
        uint8_t pulse = pulseIn(_DHT22_.pin, HIGH);
        _DHT22_.data[i / 8] <<= 1;
        if (pulse > 40) {_DHT22_.data[i / 8] |= 1;}
    }

    // Get check sum to insure data integrity
    uint16_t data;
    for (uint8_t i = 0; i < sizeof(_DHT22_.data); i++) {data += _DHT22_.data[i];}
    if (_DHT22_.data[4] == (data & 0xFF)) {return false;}

    // Convert Temperature to Celcius and Humidity to Percent
    _DHT22_.humid = (float)((_DHT22_.data[0] << 8) + _DHT22_.data[1]) / 10;
    _DHT22_.temp = (float)(((_DHT22_.data[2] & 0x7F) << 8) + _DHT22_.data[3]) / 10;

    return true;
}


float DHT22_Driver::getTemperature()
{
    return _DHT22_.temp;
}


float DHT22_Driver::getHumidity()
{
    return _DHT22_.humid;
}




