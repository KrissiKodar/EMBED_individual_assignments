OBJS = mult2.o

all: mult2

mult2: $(OBJS)
	gcc -o mult2 $(OBJS) -l pthread rt

%.o: src/%.cpp
	gcc -o $@ -c $< -I include

clean:
	rm -f *.o mult2
	echo Clean done