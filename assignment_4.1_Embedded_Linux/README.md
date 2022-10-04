# Assignment 4.1

## Part 1

Could not get the SSH working through USB connection. It was an issue with USB drivers for windows 11.

I ended up connection to the Raspeberry Pi Zero W2 through SSH in my home WIFI.

Helloworld was trivial so the .cpp file for that is not included here.

## Part 2

Copied the code from the presentation and got the Makefile to work correctly

## Part 3

It seems to me that the make command only compiles those files that I have changed, when I test it out.

The FIFO seems to be working well, every $x$ seconds I put a value in the FIFO object and every $y$ seconds I read a value from the FIFO object (it gets read then removed).
If the FIFO object is full shouldn't the oldest value get overwritten? I did that and It seemed to be working well. 
