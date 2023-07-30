


#ifndef DHT22_DRIVER_H
#define DHT22_DRIVER_H


#include <Arduino.h>


#define DHT22_PIN 5


typedef struct
{
    uint8_t     pin = 5;

    uint8_t data[5] = {0};

    float      temp = 0;
    float     humid = 0;

} Sensor;


class DHT22_Driver 
{
private:

    Sensor _DHT22_;

public:

     DHT22_Driver();
    ~DHT22_Driver();

    void begin();
    bool  read();
    void print();

};


static DHT22_Driver myDHT22;


#endif