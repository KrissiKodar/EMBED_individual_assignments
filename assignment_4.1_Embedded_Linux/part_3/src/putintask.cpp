#include <unistd.h>
#include <pthread.h>
#include <stdint.h>
#include <stdio.h>
#include "fifo_ring.h"
#include "putintask.h"

extern pthread_mutex_t sharedVariableMutex;
extern int counter;
extern Fifo_ring gshared_fifo;

void *putinTask(void *param)
{
    while(1)
    {
        /* Delay for 2 seconds */
        sleep(1);

        /* Wait for the mutex to become available. */
        pthread_mutex_lock(&sharedVariableMutex);

        //gsharedVariable++;
        gshared_fifo.put(counter);
        printf("Put in fifo: %d was placed\n", counter);
        counter++;
        

        /* Release the mutex. */
        pthread_mutex_unlock(&sharedVariableMutex);
    }
    
}