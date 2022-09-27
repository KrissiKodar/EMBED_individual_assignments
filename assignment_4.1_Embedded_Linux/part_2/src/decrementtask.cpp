#include <unistd.h>
#include <pthread.h>
#include <stdint.h>
#include <stdio.h>
#include "decrementtask.h"

extern pthread_mutex_t sharedVariableMutex;
extern int32_t gsharedVariable;

void *decrementTask(void *param)
{
    while(1)
    {
        /* delay for 7 seconds */
        sleep(7);

        /* Wait for the mutex to become available. */
        pthread_mutex_lock(&sharedVariableMutex);

        gsharedVariable--;

        printf("Decrement Task: shared var is %d\n", gsharedVariable);

        /* Release the mutex. */
        pthread_mutex_unlock(&sharedVariableMutex);
    }
    
}