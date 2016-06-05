CC = g++
CPPFLAGS = -ggdb --std=c++11 -Wall -ansi -pedantic
OBJS = obj/interpreter.o obj/brainfuck.o

all: interpreter
interpreter: $(OBJS)
	$(CC) -o $@ $^
obj/%.o: src/%.cpp
	$(CC) -c $(CPPFLAGS) -o $@ $^
clean:
	rm interpreter obj/* src/*~ 