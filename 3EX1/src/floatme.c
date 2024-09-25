#include "floatme.h"
pthread_mutex_t mutex;
pthread_cond_t pthread_cond_read;
void* Float(void* param) {
  char* number_string = malloc(20 * sizeof(char));
  double* true_number = (double*)param;

  while (*true_number >= -1 && *true_number <= 100) {
    pthread_mutex_lock(&mutex);
    printf("Type number from 0 to 1\n");
    fgets(number_string, 20, stdin);
    *true_number = atof(number_string);
    param = (void*)true_number;
    if (*true_number > 100) {
      exit(1);
    }
    pthread_cond_wait(&pthread_cond_read, &mutex);
    pthread_mutex_unlock(&mutex);
  }
}