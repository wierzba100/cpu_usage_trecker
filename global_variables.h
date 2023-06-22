//
// Created by filip on 18.06.23.
//

#ifndef CPU_USAGE_TRACKER_GLOBAL_VARIABLES_H
#define CPU_USAGE_TRACKER_GLOBAL_VARIABLES_H

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>

#define WATCHDOG_TIMEOUT 100
#define NR_OF_THREADS 4
#define BUFFER_SIZE 10

typedef struct{
    unsigned long user;
    unsigned long nice;
    unsigned long system;
    unsigned long idle;
    unsigned long iowait;
    unsigned long irq;
    unsigned long softirq;
    unsigned long steal;
    unsigned long guest;
    unsigned long guest_nice;
} CPU_Data;

typedef struct{
    CPU_Data** const ReaderData;
    double** const PrinterData;

}AnalyzerData;

extern long number_of_processors;

extern void thread_is_working(int thread_nr);

extern volatile sig_atomic_t done;
extern void term(int);

/*extern int readerQueueRear;
extern int readerQueueFront;
extern int usageQueueRear;
extern int usageQueueFront;*/

#endif //CPU_USAGE_TRACKER_GLOBAL_VARIABLES_H
