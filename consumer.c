// consumer code
// Kaila Anderson
// November 2, 2023

#include "sharedMem.h"

int main()
{
  while(1){
    int consume;

    sem_wait(&Full); // wait untill buffer is full
    pthread_mutex_lock(&mutex);
    consume = buffer[count-1];
    count--;
    pthread_mutex_unlock(&mutex);
    sem_post(&Empty);

    printf("Consumed %d\n", consume);
  }
}
