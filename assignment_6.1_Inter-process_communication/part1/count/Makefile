OBJS = count_code.o

all: count_code

count_code: $(OBJS)
	g++ -o count_code $(OBJS) -l pthread 

%.o: src/%.cpp
	g++ -o $@ -c $< -I include

clean:
	rm -f *.o count_code
	echo Clean done