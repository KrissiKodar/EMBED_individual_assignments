OBJS = command.o

all: command

command: $(OBJS)
	gcc -o command $(OBJS) -l pthread 

%.o: src/%.cpp
	gcc -o $@ -c $< -I include

clean:
	rm -f *.o command
	echo Clean done