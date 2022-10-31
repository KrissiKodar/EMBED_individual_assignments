OBJS = increment.o

all: increment

increment: $(OBJS)
	g++ -o increment $(OBJS) -lpthread -lrt

%.o: src/%.cpp
	g++ -o $@ -c $< -I include

clean:
	rm -f *.o increment
	echo Clean done