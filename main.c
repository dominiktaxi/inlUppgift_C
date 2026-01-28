#include <stdio.h>
#include "eventlog.h"
int main()
{
    Table table;
    table = eventlog_create(10);
    eventlog_insert(3, 180, &table);
    eventlog_insert(3, 180, &table);
    eventlog_insert(4, 180, &table);
    eventlog_insert(5, 180, &table);
    eventlog_insert(9, 180, &table);
    eventlog_insert(3, 180, &table);
    eventlog_insert(3, 180, &table);
    eventlog_insert(3, 180, &table);
    
    eventlog_deleteById(3, &table);
    eventlog_printAll(&table);
    return 0;
}