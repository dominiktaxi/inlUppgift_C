#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "eventlog.h"



EventList* eventlog_create()
{
    EventList* new = malloc(sizeof(EventList));
    new->head = NULL;
    new->tail = NULL;
    return new;
}

void eventlog_destroy(EventList* list)
{
    assert(list != NULL);
    Node* temp = list->head;
    Node* next = NULL;
    while(temp != NULL)
    {
        next = temp->next;
        free(temp);
        temp = next;
    }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

int eventlog_size(const EventList* list)
{
    return list->size;
}


void eventlog_append(EventList* list, Event event)
{
    assert(list != NULL);
    if(list->head == NULL)
    {
        list->head = malloc(sizeof(Node));
        assert(list->head != NULL);
        list->tail = list->head;
        list->head->event = event;
        list->head->next = NULL;
    }
    else
    {
        list->tail->next = malloc(sizeof(Node));
        assert(list->tail->next != NULL);
        list->tail->next->event = event;
        list->tail = list->tail->next;
        list->tail->next = NULL;
    }
    list->size++;
}

Event eventlog_getEvent(const EventList* list, int index)
{
    assert (list != NULL);
    assert (index < list->size && index >= 0);
    Node* temp = list->head;
    for(int i = 0; i < index; i++)
    {
        temp = temp->next;
    }
    assert(temp != NULL);
    return temp->event;
}

void eventlog_set(EventList* list, int index, Event event)
{
    assert(list != NULL);
    assert(index < list->size && index >= 0);
    Node* temp = list->head;

    for(int i = 0; i < index; i++)
    {
        temp = temp->next;
    }
    assert(temp != NULL);
    temp->event = event;
}

int eventlog_find(int key, int* outValue, const Table* table)
{
    return 0;
}




void eventlog_printAll(const Table* table)
{
   
}
