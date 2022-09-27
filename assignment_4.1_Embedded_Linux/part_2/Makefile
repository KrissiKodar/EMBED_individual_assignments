OBJS = main.o incrementtask.o decrementtask.o

all: part2

part2: $(OBJS)
	g++ -o part2 $(OBJS) -l pthread 

%.o: src/%.cpp
	g++ -o $@ -c $< -I include

clean:
	rm -f *.o part2
	echo Clean done