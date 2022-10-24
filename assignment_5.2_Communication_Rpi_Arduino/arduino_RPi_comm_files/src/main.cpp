#include <Arduino.h>

/* Arduino Serial Command Processor */

int ledPin = 11;          // LED with PWM brightness control

void setup() {            // called once on start up
   // A baud rate of 115200 (8-bit with No parity and 1 stop bit)
   Serial.begin(115200, SERIAL_8N1);
   pinMode(ledPin, OUTPUT);         // the LED is an output
}


// part 3
void loop() {              // loops forever
   uint8_t command;
   uint8_t level;
   char buffer[100];       // stores the return buffer on each loop   
   if (Serial.available()>0){                 // bytes received
      Serial.readBytes(buffer, 2); // read 2 bytes
      command = buffer[0];           // first byte is command
                                    // if first byte is 2 then set the brightness of the LED
      if(command==2){   // if first byte is 2 then set the brightness of the LED
         level = buffer[1] ;    // extract the LED brightness level from buffer
         // is it in range?
         // it can't really be out of range because the level is a uint8_t (unsigned)
         // so if you send a value greater than 255 it will wrap around to 0
         // or if you send a value less than 0 it will wrap around to 255
         if(level>=0 && level<=255){          
            analogWrite(ledPin, level);       // yes, write out
            sprintf(buffer, "Set brightness to %d", level);
         }
         else{                                // no, error message back
            sprintf(buffer, "Error: %d is out of range", level);
         } 
      }                                       // otherwise, unknown cmd
      else{ sprintf(buffer, "Unknown command: %d", command); }
      Serial.print(buffer);               // send the buffer to the RPi
   }
}


// part 2

/* void loop() {              // loops forever
   String command;
   char buffer[100];       // stores the return buffer on each loop   
   if (Serial.available()>0){                 // bytes received
      command = Serial.readStringUntil('\0'); // C strings end with \0
      if(command.substring(0,4) == "LED "){   // begins with "LED "?
         String intString = command.substring(4, command.length());
         int level = intString.toInt();       // extract the int
         if(level>=0 && level<=255){          // is it in range?
            analogWrite(ledPin, level);       // yes, write out
            sprintf(buffer, "Set brightness to %d\n", level);
         }
         else{                                // no, error message back
            sprintf(buffer, "Error: %d is out of range\n", level);
         } 
      }                                       // otherwise, unknown cmd
      else{ sprintf(buffer, "Unknown command: %s\n", command.c_str()); }
      Serial.print(buffer);               // send the buffer to the RPi
   }
} */