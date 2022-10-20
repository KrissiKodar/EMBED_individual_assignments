OBJS = part2_code.o

all: part2_code

part2_code: $(OBJS)
	g++ -o part2_code $(OBJS) -l pthread 

%.o: src/%.cpp
	g++ -o $@ -c $< -I include

clean:
	rm -f *.o part2_code
	echo Clean done