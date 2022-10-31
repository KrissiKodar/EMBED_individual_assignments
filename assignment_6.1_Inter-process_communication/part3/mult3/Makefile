OBJS = mult3.o

all: mult3

mult3: $(OBJS)
	gcc -o mult3 $(OBJS) -l pthread rt

%.o: src/%.cpp
	gcc -o $@ -c $< -I include

clean:
	rm -f *.o mult3
	echo Clean done