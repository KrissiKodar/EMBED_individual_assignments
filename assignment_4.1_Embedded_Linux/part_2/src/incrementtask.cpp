#include <unistd.h>
#include <pthread.h>
#include <stdint.h>
#include <stdio.h>
#include "incrementtask.h"

extern pthread_mutex_t sharedVariableMutex;
extern int32_t gsharedVariable;

void *incrementTask(void *param)
{
    while(1)
    {
        /* Delay for 3 seconds */
        sleep(3);

        /* Wait for the mutex to become available. */
        pthread_mutex_lock(&sharedVariableMutex);

        gsharedVariable++;

        printf("Increment Task: shared var is %d\n", gsharedVariable);

        /* Release the mutex. */
        pthread_mutex_unlock(&sharedVariableMutex);
    }
    
}