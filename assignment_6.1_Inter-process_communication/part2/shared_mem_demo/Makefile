OBJS = shared-mem-demo.o

all: shared-mem-demo

shared-mem-demo: $(OBJS)
	gcc -o shared-mem-demo $(OBJS) -l pthread rt

%.o: src/%.cpp
	gcc -o $@ -c $< -I include

clean:
	rm -f *.o shared-mem-demo
	echo Clean done