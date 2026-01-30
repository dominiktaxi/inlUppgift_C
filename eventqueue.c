#include "eventqueue.h"
#include <assert.h>

EventQueue eventqueue_create(int capacity)
{
    EventQueue new;
    new.size = capacity;
    new.events = malloc(sizeof(Event) * capacity);
    new.front = 0;
    return new;
}

void eventqueue_destroy(EventQueue* q)
{
    assert(!eventQueue_isEmpty(q));
    free(q->events);
    q->events = NULL;
    q->size = 0;
    q->front = 0;
    q->amountOfEvents = 0;
    assert(q->events == NULL);
}

int eventqueue_isEmpty(const EventQueue* q)
{
    return q->front == 0;
}

int eventqueue_isFull(const EventQueue* q)
{
    return q->front == 8;
}

//ingen assert q != NULL för att Eventq skapas på stacken per definition
int eventqueue_enqueue(EventQueue* q, Event event)
{
    assert(!eventq_isFull(q));
    int index = (q->front + q->amountOfEvents) % q->size;
    *(q->events + index) = event;
    q->amountOfEvents++;
}
    
int eventqueue_dequeue(EventQueue* q, Event* eventOut)
{
   if(eventqueue_isEmpty(q)) { return 0; }
   int index = q->front;
   q->front = (q->front + 1) % q->size;
   q->amountOfEvents--;
   eventOut = (q->events + index);
}

void eventqueue_clear(EventQueue* q)
{
    q->amountOfEvents = 0;
    q->front = 0;
}

int eventqueue_size(const EventQueue* q)
{
    return q->size;
}