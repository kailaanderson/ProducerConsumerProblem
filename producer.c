// producer code
// Kaila Anderson

#include "sharedMem.h"

int main() 
{
  while(1){
    int data = rand() % 100; //generate random numeber

    sem_wait(&Empty); // wait until empty is true
    pthread_mutex_lock(&mutex); // lock access to thread
    buffer[count] = data; // put data into buffer
    count++;
    pthread_mutex_unlock(&mutex); //unlock access
    sem_post(&Full); 
}
