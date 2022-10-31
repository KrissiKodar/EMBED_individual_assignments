OBJS = mult3.o

all: mult3

mult3: $(OBJS)
	g++ -o mult3 $(OBJS) -lpthread -lrt

%.o: src/%.cpp
	g++ -o $@ -c $< -I include

clean:
	rm -f *.o mult3
	echo Clean done