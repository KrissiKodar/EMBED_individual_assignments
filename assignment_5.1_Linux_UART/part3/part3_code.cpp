#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<termios.h>   // using the termios.h library
#include<stdint.h>
#include <pthread.h>

uint32_t counter = 0;
uint32_t received_counter = 0;
int fd, count;

pthread_t write_incrementObj;
pthread_t read_printObj;

void *write_i(void *param);
void *read_p(void *param);


void *write_i(void *param)
{
   while(1)
   {
      sleep(1);
      if ((count = write(fd, &counter, sizeof(counter)))<0) // transmit
         {         
            perror("Failed to write to the output\n");
            // return -1;
         }
      counter++;
   }
}

void *read_p(void *param)
{
   while(1)
   {
      if ((count = read(fd, &received_counter, sizeof(counter)))<0) // receive
            {         
               perror("Failed to read from the input\n");
            }
      if (count==0) 
         {
            printf("There was no data available to read!\n");
         }
      else 
         {
            printf("%d\n", received_counter);
            printf("Bytes returned from the serial port: %d\n", count);
         }
}
}



int main(){
   // device opened for blocking read
   fd = open("/dev/ttyS0", O_RDWR | O_NOCTTY);
   if (fd < 0){
         perror("UART: Failed to open the file.\n");
         return -1;
      }
   struct termios options;       // the termios structure is vital
   tcgetattr(fd, &options);    // sets the parameters for the file

   cfmakeraw(&options); // set raw mode

   options.c_cc[VMIN] = sizeof(counter); // 4 in this case
   
   //options.c_cc[VTIME] = 0;
   //options.c_cflag = B57600;

   tcflush(fd, TCIFLUSH);            // discard file information

   tcsetattr(fd, TCSANOW, &options); // changes occur immmediately

   pthread_create(&write_incrementObj, NULL, write_i, NULL);
   pthread_create(&read_printObj, NULL, read_p, NULL);
   
   /* Allow the tasks to run. */
   pthread_join(write_incrementObj, NULL);
   pthread_join(read_printObj, NULL);

   close(fd);
   return 0;
}