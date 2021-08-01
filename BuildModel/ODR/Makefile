out: main.o math.o vector.o
	g++ -std=c++20 main.o math.o vector.o -o out

all: main.cpp math.cpp vector.cpp
	g++ -v -std=c++20 main.cpp math.cpp vector.cpp -o out

main.o: main.cpp
	g++ -c -std=c++20 main.cpp -o main.o

math.o: math.cpp
	g++ -c -std=c++20 math.cpp -o math.o

vector.o: vector.cpp math.o
	g++ -c -std=c++20 vector.cpp math.o -o vector.o

clean: 
	rm main.o math.o vector.o out lib.o 