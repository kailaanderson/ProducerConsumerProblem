// created in Linux and transferred to github
//Kaila Anderson
//OS Producer Consumer Project
//November 2, 2023

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <semaphore.h>

#define THREAD_NUM 2

sem_t Empty; //declaring semaphores
sem_t Full;

pthread_t producer; //declaring producer thread
pthread_t consumer; //declaring consumer thread

pthread_mutex_t mutex; //declaring mutex lock

int buffer[2]; //buffer that holds two values
int count = 0; //used to control how many times code iterates
