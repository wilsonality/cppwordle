#%.o: %.cpp
#	$(CC) $(CFLAGS) - $< -o $@

all: my_program

my_program: main.o wordle.o
	g++ $@ -o $^

main.o: wordle.h main.cpp
	$(CC) $(CFLAGS) - $< -o $@

wordle.o: wordle.cpp
	$(CC) $(CFLAGS) - $< -o $@

clear:
	rm -f *.o my_program