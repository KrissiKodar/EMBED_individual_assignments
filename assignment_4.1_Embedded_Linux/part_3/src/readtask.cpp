#include <unistd.h>
#include <pthread.h>
#include <stdint.h>
#include <stdio.h>
#include "fifo_ring.h"
#include "readtask.h"

extern pthread_mutex_t sharedVariableMutex;
extern Fifo_ring gshared_fifo;

void *readTask(void *param)
{
    while(1)
    {
        /* delay for 7 seconds */
        sleep(5);

        /* Wait for the mutex to become available. */
        pthread_mutex_lock(&sharedVariableMutex);

        //gsharedVariable--;


        printf("Read Task: %d was read\n", gshared_fifo.get());

        /* Release the mutex. */
        pthread_mutex_unlock(&sharedVariableMutex);
    }
    
}