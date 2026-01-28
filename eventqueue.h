#ifndef EVENTQUEUE_H
#define EVENTQUEUE_H
#include <stddef.h> 
#include <stdlib.h>
#include "event.h"
typedef struct EventLog EventLog;

typedef struct Node
{
    Event event;
    struct Node* next;
}Node;

typedef struct EventLog
{
    Node* head;
    Node* tail;
    int size;
    int capacity;
}EventLog;

EventLog* eventlog_create(int capacity);
int eventlog_enqueue(EventLog*, Event);
Event eventlog_dequeue(EventLog*);
void eventlog_clear(EventLog*);
void eventlog_destroy(EventLog*);
int eventlog_size(const EventLog*);
#endif