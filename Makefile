#%.o: %.cpp
#	$(CC) $(CFLAGS) - $< -o $@

all: program

program: main.o wordle.o
	g++ -o $@ $^

main.o: main.cpp
	g++ -c $<

wordle.o: wordle.cpp
	g++ -c $<

clean:
	rm -f *.o program