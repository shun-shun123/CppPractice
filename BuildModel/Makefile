# main.cppとmath.cppから実行可能なoutを生成する

# 「ターゲット:依存ファイル」という形式
# ターゲットとは生成したい実行ファイルのこと
# 依存ファイルとはターゲットの生成に必要なファイル
out:main.o math.o hello.o
# ここで具体的なコマンドを記述する
	g++ main.o math.o hello.o -o out

main.o: main.cpp
	g++ -c -std=c++20 main.cpp -o main.o

math.o: math.cpp
	g++ -c -std=c++20 math.cpp -o math.o

hello.o: mylib/hello.cpp
	g++ -c -std=c++20 mylib/hello.cpp -o hello.o

clean:
	rm main.o math.o out