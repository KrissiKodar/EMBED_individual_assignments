OBJS = part3_app.o

all: part3_app

part3_app: $(OBJS)
	gcc -o part3_app $(OBJS) -l pthread 

%.o: src/%.cpp
	gcc -o $@ -c $< -I include

clean:
	rm -f *.o part3_app
	echo Clean done