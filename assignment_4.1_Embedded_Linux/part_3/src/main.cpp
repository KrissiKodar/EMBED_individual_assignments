#include <unistd.h>
#include <pthread.h>
#include <stdint.h>
#include "putintask.h"
#include "readtask.h"
#include "fifo_ring.h"



pthread_t putinTaskObj;
pthread_t readTaskObj;

pthread_mutex_t sharedVariableMutex;

//int32_t gsharedVariable = 0;
Fifo_ring gshared_fifo;
int counter = 1;

int main(void)
{
    /* Create the mutex for accessing the shared variable using the
    * default attributes. */
    pthread_mutex_init(&sharedVariableMutex, NULL);


    /* Create the increment and decrement tasks using the default task
    * attributes. Do not pass in any parameters to the tasks. */
    pthread_create(&putinTaskObj, NULL, putinTask, NULL);
    pthread_create(&readTaskObj, NULL, readTask, NULL);

    /* Allow the tasks to run. */
    pthread_join(putinTaskObj, NULL);
    pthread_join(readTaskObj, NULL);

    return 0;
}