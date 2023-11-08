// consumer code
// Kaila Anderson
// November 2, 2023

#include "sharedMem.h"

void* consume(){
  while(1){
    int consume; //where to hold the consumed number

    sem_wait(&Full); // wait untill buffer is full
    pthread_mutex_lock(&mutex); //lock access to the buffer
    for(int i = 0; i < 2; ++i){
        consume = buffer[i]; //consume each element and output the number that was consumed 
        printf("Consumed: ");
        printf("%d", consume);
    }
    pthread_mutex_unlock(&mutex); //unlock access
    sem_post(&Empty); //signal that the buffer is empty
  }
}
int main()
{
  pthread_create(&consumer, NULL, consume, NULL); //create the thread and call the consume function
  consume();
  sem_init(&Full, 0, 0); // initialize the semaphore
}
