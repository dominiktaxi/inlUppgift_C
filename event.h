#ifndef EVENT_H
#define EVENT_H

typedef struct Event
{
    int timeStamp;
    int sensorId;
    int value;
    enum TYPE  
    {
        TEMP,
        BUTTON,
        MOTION
    }type;
}Event;


#endif