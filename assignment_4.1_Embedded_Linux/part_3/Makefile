OBJS = main.o putintask.o readtask.o fifo_ring.o

all: part3

part3: $(OBJS)
	g++ -o part3 $(OBJS) -l pthread 

%.o: src/%.cpp
	g++ -o $@ -c $< -I include

clean:
	rm -f *.o part3
	echo Clean done