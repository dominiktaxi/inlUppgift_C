#ifndef EVENTLOG_H
#define EVENTLOG_H
#include "event.h"
typedef struct Node
{
    Event event;
    struct Node* next;
} Node;

typedef struct EventList
{
    Node* head;
    Node* tail;
    int size;
}EventList;



EventList* eventlog_create();
void eventlog_destroy(EventList*);
int eventlog_size(const EventList*);
void eventlog_append(EventList*, Event);
Event eventlog_getEvent(const EventList*, int index);
void eventlog_set(EventList*, int, Event);


void eventlog_printAll(const Table*);


#endif