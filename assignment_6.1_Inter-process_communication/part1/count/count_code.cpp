#include<stdio.h>
#include <unistd.h>
#include <iostream>

int main(){
   int counter = 0;
   while (true)
   {
      std::cout << "Counter: " << counter << std::endl;
      sleep(1);
      counter++;
   }
   
   return 0;
}