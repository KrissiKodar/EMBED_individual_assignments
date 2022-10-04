#include<fcntl.h>
#include<unistd.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define BUFFER_LENGTH 256  

int main(void)
{
    int exit_counter = 0;
    int end_program_time = 10;
    int msec;
    int fd;
    int ret;
    fd = open("/dev/mydev", O_RDWR);

    // timer (using relative timers not delay)
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    while(1)
    {
        clock_gettime(CLOCK_MONOTONIC, &end);
        msec = (end.tv_sec - start.tv_sec) * 1000 + (end.tv_nsec - start.tv_nsec) / 1000000;
        // every 1000 msec write variable length string to the device
        if(msec > 1000)
        {
            char toDevice[BUFFER_LENGTH];
            int length = rand() % 256;
            for(int i = 0; i < length; i++)
            {
                toDevice[i] = rand() % 256;
            }
            ret = write(fd, toDevice, strlen(toDevice));
            exit_counter++;
            clock_gettime(CLOCK_MONOTONIC, &start);
        }

        // after en_program_time seconds exit and close the device
        if(exit_counter > end_program_time)
        {
            ret = close(fd);
            break;
        }
    }
    return 0;
}