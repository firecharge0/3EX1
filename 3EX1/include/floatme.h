#ifndef FLOAT_H
#define FLOAT_H
#include <curses.h>
#include <math.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
extern pthread_mutex_t mutex;
extern pthread_cond_t pthread_cond_read;
void* Float(void* param);

#endif