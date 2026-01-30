#ifndef TEMPHUM_H
#define TEMPHUM_H

typedef struct Data
{
    int temperature;
    int humidity;
} SensorData;
void temphum_init();
Data temphum_read();

#endif