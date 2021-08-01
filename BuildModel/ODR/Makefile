out: main.o math.o vector.o
	g++ -std=c++20 main.o math.o vector.o -o out

main.o: main.cpp
	g++ -c -std=c++20 main.cpp -o main.o

math.o: math.cpp
	g++ -c -std=c++20 math.cpp -o math.o

vector.o: vector.cpp
	g++ -c -std=c++20 vector.cpp -o vector.o

clean: 
	rm main.o math.o vector.o out