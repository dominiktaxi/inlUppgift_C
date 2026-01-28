#include "eventqueue.h"
#include <assert.h>

EventLog* eventqueue_create(int capacity)
{
    if(capacity <= 0) return NULL;
    EventLog* new = malloc(sizeof(EventLog));
    new->head = NULL;
    new->tail = NULL;
    new->capacity = capacity;
    new->size = 0;
    return new;
}

int eventqueue_enqueue(EventLog* log, Event event)
{
    Node* new = malloc(sizeof(Node));
    if(new == NULL) return 0;

    new->event = event;
    if(log->size < log->capacity)
    {
        if(log->tail == NULL)
        {
            log->tail = new;
            log->head = new;
            log->tail->next = NULL;
        }
        else
        {
            log->tail->next = new;
            log->tail = new;
        }
    }
}

Event eventqueue_dequeue(EventLog* log)
{
    assert(log != NULL);
    assert(log->size > 0);
    if(log->tail == log->head)
    {
        assert(log->size == 1);
        Event event = log->head->event;
        free(log->head);
        log->head = NULL;
        log->tail = NULL;
        log->size--;
        return event;
    }
    else
    {
        Event event = log->head->event;
        Node* temp = log->head;
        log->head = log->head->next;
        free(temp);
        log->size--;
        return event;
    }
}

void eventqueue_clear(EventLog* log)
{
    assert(log != NULL);
    Node* temp = log->head;
    while(log->head != NULL)
    {
        log->head = log->head->next;
        free(temp);
        temp = log->head;
    }
    log->tail = NULL;
    log->size = 0;
    assert(log->tail == NULL && log->head == NULL);
}

//CALLER MUST SET POINTER TO NULL
void eventqueue_destroy(EventLog* log)
{
    assert(log != NULL);
    Node* temp = log->head;
    while(log->head != NULL)
    {
        log->head = log->head->next;
        free(temp);
        temp = log->head;
    }
    free(log);
}

int eventqueue_size(const EventLog* log)
{
    return log->size;
}