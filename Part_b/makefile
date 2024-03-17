all: output run

output: main.o grid.o dictionary.o
	g++ -g main.o grid.o dictionary.o -o output 

run:
	./output

main.o: grid.hpp dictionary.hpp main.cpp 
	g++ -c main.cpp

grid.o: grid.hpp grid.cpp
	g++ -c grid.cpp

dictionary.o: dictionary.hpp dictionary.cpp
	g++ -c dictionary.cpp

clean:
	rm *.o