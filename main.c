#include <stdio.h>
#include "eventlog.h"
int main()
{
    Table table;
    table = eventlog_create(10);
    
    Event events[100];
    for(int i = 0; i < 100; i++)
    {
        events[i].sensorId = i % 10;
        events[i].timeStamp = i;
        events[i].value = i * 2;
    }

    for(int i = 0; i < 100; i++)
    {
        eventlog_insert(events[i], &table);
    }

    
    //eventlog_deleteById(3, &table);
    //eventlog_destroy(&table);
    eventlog_printAll(&table);
    eventlog_destroy(&table);
    printf("dude");
    table = eventlog_create(10);
   for(int i = 0; i < 100; i++)
    {
        eventlog_insert(events[i], &table);
    }
    eventlog_printAll(&table);
    return 0;
}