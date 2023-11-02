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

sem_t Empty;
sem_t Full;

pthread_mutex_t mutex;

int buffer[2];
int count = 0;
