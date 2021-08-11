all: main.o
	g++ -std=c++20 -o out main.o

main.o: main.cpp
	g++ -c -o main.o main.cpp -std=c++20

clean:
	rm main.o out