# ProducerConsumerProblem
README file
Kaila Anderson
Operating Systems Programming Assignment #1
November 7, 2023

For this assignment we had to implement code that would solve the producer consumer problem. I created a header file named sharedMem.h, to establish the pieces of information that needed to be shared between each file. I also have two files, producer.c and consumer.c, to implement the code for the producer and consumer to run simultaneously. 
This code is compiled with: 
gcc producer.c -pthread -lrt -o producer
gcc consumer.c -pthread -ltr -o consumer
./producer & ./consumer

sharedMem.h
The first two declarations are two semaphores, full and empty. I created these semaphores so the producer would know to produce data when the buffer was empty and so the consumer would know to consume data when the buffer was full. I also created threads for the producer and consumer to create a multithreaded program. The mutex lock was used to ensure mutual exclusion was upheld. The buffer array with size of 2 represented the "table" where data would be stored. Lastly, I created a count variable to keep track of how many times the code implemented. 

producer.c
In the main function for this code, I created the thread "producer" that called the produce function. I also initialized the empty semaphore. In the produce function, "sem_wait(&Empty) is used so the producer waits until the buffer is empty to begin producing data. When confirming that it is empty, it locks the mutex lock and continues to the critical section where it takes a random number from 1-100 to place into the array. Once the section is over, it unlocks the lock and posts the semaphore, signaling that the consumer may execute its code. 

consumer.c
In the main function for this code, I created the thread "consumer" that calls the consume function. I also initialized the full semaphore. In the consume function, it uses an integer variable to hold the value consumed. The code waits until the full semaphore grants access, locks the mutex lock, and continues to the critical section. In this section, the consumer goes through the buffer, consuming the number and printing its value. It then unlocks the lock and posts the semaphore, signaling that the producer may produce new values. 

The overall implementation of this programming assignment was difficult as it was my first time coding semaphores with multithreaded implementation, however I was able to experiement and learn more about the rules, libraries, and how they are used in code. 

