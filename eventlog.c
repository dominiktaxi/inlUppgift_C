#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "eventlog.h"



Table eventlog_create(int size)
{
    Bucket** new = malloc(sizeof(Bucket*) * size);
    assert(new != NULL);
    for(int i = 0; i < size; i++)
    {
        *(new + i) = NULL;
    }
    Table table;
    table.size = size;
    table.buckets = new;
    return table;
}

int eventlog_insert(Event event, const Table* table)
{
    int id = event.sensorId;
    assert(id < table->size);
    Bucket* new = malloc(sizeof(Bucket));
    assert(new != NULL);
    new->event = event;
    new->next = NULL;

    if(*(table->buckets + id) == NULL)
    {
        *(table->buckets + id) = new;
        return 1;
    }

    Bucket* temp = *(table->buckets + id);
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new;
}

int eventlog_find(int key, int* outValue, const Table* table)
{
    return 0;
}

int eventlog_deleteById(int id, Table* table)
{
    assert(id < table->size);
    Bucket* temp = *(table->buckets + id);
    if(temp != NULL)
    {
        Bucket** control = table->buckets + id;
        while(temp != NULL)
        {
            *control = (*control)->next;
            free(temp);
            temp = *control;
        }
        return 1;
    }
    assert(*(table->buckets + id) == NULL);
    return 0;
}

void eventlog_printAll(const Table* table)
{
   for(int i = 0; i < table->size; i++)
   {
        if(*(table->buckets + i) != NULL)
        {
            Bucket* temp = *(table->buckets + i);
            while(temp != NULL)
            {
                printf("ID: %d  Value: %d\n", temp->event.sensorId, temp->event.value);
                temp = temp->next;
            }
        }
   }
}
