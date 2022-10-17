OBJS = part3_code.o

all: part3_code

part3_code: $(OBJS)
	gcc -o part3_code $(OBJS) -l pthread 

%.o: src/%.cpp
	gcc -o $@ -c $< -I include

clean:
	rm -f *.o part3_code
	echo Clean done