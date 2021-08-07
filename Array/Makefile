all: main.o
	g++ -std=c++20 -o out main.o

main.o: main.cpp
	g++ -std=c++20 -c -o main.o main.cpp

clean:
	rm main.o out