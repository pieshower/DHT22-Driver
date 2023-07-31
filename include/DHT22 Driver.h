


#ifndef DHT22_DRIVER_H
#define DHT22_DRIVER_H


#include <Arduino.h>


#define DHT22_PIN 5


typedef struct
{
    uint8_t     pin = 0;

    uint8_t data[5] = {0};

    float      temp = 0;
    float     humid = 0;

} Sensor;


class DHT22_Driver 
{
private:

    Sensor _DHT22_;

public:

    void begin(int pin = 5);

    bool  read();

    float getTemperature();
    float getHumidity();

};


#endif