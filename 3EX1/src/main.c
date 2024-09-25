#include <curses.h>
#include <math.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "floatme.h"
#include "printarcsine.h"

int main() {
  pthread_t p_float;
  pthread_t p_arcsine;
  pthread_attr_t attr;
  pthread_attr_init(&attr);
  double floating_point = -1;
  pthread_mutex_init(&mutex, NULL);
  pthread_create(&p_float, &attr, Float, (void*)&floating_point);
  pthread_create(&p_arcsine, &attr, PrintArcSine, (void*)&floating_point);
  pthread_join(p_float, NULL);
  pthread_join(p_arcsine, NULL);
  return 0;
}
