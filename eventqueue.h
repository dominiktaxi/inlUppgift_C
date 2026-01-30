#ifndef EventQueue_H
#define EventQueue_H
#include <stddef.h> 
#include <stdlib.h>
#include "event.h"


typedef struct EventQueue
{
    int front;
    int amountOfEvents;
    int size;
    Event* events;
}EventQueue;

EventQueue eventQueue_create(int capacity);
void eventQueue_destroy(EventQueue*);
int eventQueue_isEmpty(const EventQueue*);
int eventQueue_isFull(const EventQueue*);
int eventQueue_enqueue(EventQueue*, Event);
int eventQueue_dequeue(EventQueue*);
void eventQueue_clear(EventQueue*);
int eventQueue_size(const EventQueue*);

#endif