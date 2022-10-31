OBJS = mult2.o

all: mult2

mult2: $(OBJS)
	g++ -o mult2 $(OBJS) -lpthread -lrt

%.o: src/%.cpp
	g++ -o $@ -c $< -I include

clean:
	rm -f *.o mult2
	echo Clean done