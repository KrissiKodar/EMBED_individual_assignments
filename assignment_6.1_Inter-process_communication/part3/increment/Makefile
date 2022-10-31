OBJS = increment.o

all: increment

increment: $(OBJS)
	gcc -o increment $(OBJS) -l pthread rt

%.o: src/%.cpp
	gcc -o $@ -c $< -I include

clean:
	rm -f *.o increment
	echo Clean done