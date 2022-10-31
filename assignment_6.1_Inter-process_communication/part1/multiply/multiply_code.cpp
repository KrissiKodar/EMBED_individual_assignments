#include<stdio.h>
#include <unistd.h>
#include <iostream>

int main(int argc, char *argv[]){
   int read_counter;
   int multiplier;
   multiplier = atoi(argv[1]);
   while (true)
   {  
      std::cin >> read_counter;
      std::cout << "multiplied counter: " << read_counter * multiplier << std::endl;
   }
   
   return 0;
}