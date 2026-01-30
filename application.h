#ifndef APPLICATION_H
#define APPLICATION_H
#include "eventqueue.h"
#include "eventlog.h"
#include "sensors/temphum.h"


void application_loop();

static int application_collect();


#endif