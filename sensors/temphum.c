#include "temphum.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void temphum_init()
{
    srand(time(NULL));
}

struct Data temphum_read()
{
    struct Data data;
    data.humidity = rand() % 100;
    data.temperature = 15 + rand() % (100 - 15 + 1);
    return data;
}