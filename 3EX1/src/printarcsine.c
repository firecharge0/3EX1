#include "printarcsine.h"

#include "floatme.h"

void* PrintArcSine(void* param) {
  double* num_to_arc = (double*)param;
  while (1) {
    pthread_mutex_lock(&mutex);
    if (*num_to_arc >= 0 && *num_to_arc <= 1) {
      printf("%f\n", asin(*num_to_arc));
      *num_to_arc = -1;
    }
    pthread_cond_signal(&pthread_cond_read);
    pthread_mutex_unlock(&mutex);
  }
}