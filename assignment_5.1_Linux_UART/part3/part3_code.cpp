#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<termios.h>   // using the termios.h library
#include<stdint.h>

void stdin_set(int cmd)
{
   struct termios options;
   tcgetattr(STDIN_FILENO, &options);
   switch (cmd) {
   case 1:
      options.c_lflag &= ~ICANON;
      break;
   default:
      options.c_lflag |= ICANON;
      break;
   }
   tcsetattr(STDIN_FILENO, TCSANOW, &options);
}

int main(){
   int fd, count;
   // device opened for blocking read
   if ((fd= open("/dev/ttyS0", O_RDWR | O_NOCTTY))<0){
      perror("UART: Failed to open the file.\n");
      return -1;
   }

   struct termios options;       // the termios structure is vital
   tcgetattr(fd, &options);    // sets the parameters for the file

   cfmakeraw(&options);

   options.c_cc[VMIN] = 1;

   if (cfsetispeed(&options, B57600) < 0 || cfsetospeed(&options, B57600) < 0) {
      perror("UART: ERROR setting baud rate.\n");
      return -1;
   }
   //tcflush(fd, TCIFLUSH);            // discard file information
   tcsetattr(fd, TCSANOW, &options); // changes occur immmediately
   const size_t MSG_LEN = 2;
   uint8_t msg[MSG_LEN];
   // populate the message with integer values in binary format
   msg[0] = 18;
   msg[1] = 243;
   if ((count = write(fd, msg, MSG_LEN))<0) // transmit
      {         
         perror("Failed to write to the output\n");
         return -1;
      }
   usleep(100000);             // give the remote machine a chance to respond
   // receive buffer
   uint8_t receive[MSG_LEN];
   if ((count = read(fd, (void*)receive, MSG_LEN))<0){   //receive data
         perror("Failed to read from the input\n");
         return -1;
      }
   if (count==0) printf("There was no data available to read!\n");
      else printf("received messages: %d %d\n", receive[0], receive[1]);

   close(fd);

   return 0;
}