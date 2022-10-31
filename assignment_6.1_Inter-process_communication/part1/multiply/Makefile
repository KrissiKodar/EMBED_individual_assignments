OBJS = multiply_code.o

all: multiply_code

multiply_code: $(OBJS)
	g++ -o multiply_code $(OBJS) -l pthread 

%.o: src/%.cpp
	g++ -o $@ -c $< -I include

clean:
	rm -f *.o multiply_code
	echo Clean done