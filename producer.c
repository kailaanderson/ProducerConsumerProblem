// producer code
// Kaila Anderson

#include "sharedMem.h"

void* produce(){
  while(count > 0){
    sem_wait(&Empty); // wait until empty is true
    pthread_mutex_lock(&mutex); // lock access to thread
    for(int i = 0; i < 2; ++i){
      int data = rand() % 100; //generate random number
      buffer[i] = data; //put random number onto data table
    }
    count--; 
    pthread_mutex_unlock(&mutex); //unlock access
    sem_post(&Full); //signal that buffer is full
  }
}
int main() 
{
  pthread_create(&producer, NULL, produce, NULL); //create a thread and call produce functino
  produce();
  sem_init(&Empty, 0, 2);    
}
