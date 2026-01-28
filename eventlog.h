#ifndef EVENTLOG_H
#define EVENTLOG_H
#include "event.h"
typedef struct Bucket
{
    Event event;
    struct Bucket* next;
} Bucket;

typedef struct Table
{
    int size;
    Bucket** buckets;
}Table;

Table eventlog_create(int);
int eventlog_insert(Event, const Table*);
int eventlog_find(int, int*, const Table*);
int eventlog_deleteById(int, Table*);
void eventlog_printAll(const Table*);


#endif