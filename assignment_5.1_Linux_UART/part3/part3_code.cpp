#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<termios.h>   // using the termios.h library
#include<stdint.h>

int main(){
   int fd, count;
   // device opened for blocking read
   if ((fd= open("/dev/ttyS0", O_RDWR | O_NOCTTY))<0){
      perror("UART: Failed to open the file.\n");
      return -1;
   }

   struct termios options;       // the termios structure is vital
   tcgetattr(fd, &options);    // sets the parameters for the file

   cfmakeraw(&options); // set raw mode

   options.c_cc[VMIN] = 4;
   options.c_cc[VTIME] = 0;
   //options.c_cflag = B57600;
   
   tcflush(fd, TCIFLUSH);            // discard file information
   
   tcsetattr(fd, TCSANOW, &options); // changes occur immmediately
   
   //const size_t MSG_LEN = 1;
   //uint32_t msg[MSG_LEN];  
   uint32_t counter = 0;
   uint32_t received_counter = 0;
   while(1)
      {
         if ((count = write(fd, &counter, sizeof(counter)))<0) // transmit
         {         
            perror("Failed to write to the output\n");
            return -1;
         }
         counter++;
         sleep(1);
         if ((count = read(fd, &received_counter, sizeof(counter)))<0) // receive
            {         
               perror("Failed to read from the input\n");
               return -1;
            }
         if (count==0) 
            {
               printf("There was no data available to read!\n");
            }
         else 
            {
               printf("\n%d\n", received_counter);
               printf("characters in the serial buffer is: %d\n", count);
               printf("size of counter is %d\n", sizeof(counter));
            }
      }
   close(fd);
   return 0;
}