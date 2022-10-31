#include<stdio.h>
#include <iostream>

int main(){
   int read_counter;
   int multiplier;

   std::cout << "Enter multiplier: ";
   std::cin >> multiplier;
   while (true)
   {
      std::cin >> read_counter;
      std::cout << "multiplied counter: " << read_counter * multiplier << std::endl;
   }
   
   return 0;
}