#include <iostream>

using namespace std;

// C++の関数宣言について
// C++ compilerは上から順に見ていくので、宣言まえに関数を呼び出すとエラーが起きる
// int sum = Sum(1, 2);

int Sum(int x, int y);

int sum = Sum(1, 2);

int Sum(int x, int y) {
    return x + y;
}

// 引数名を省略することができる
// 明確に引数を使わない場合には便利かも
void OnPlayerCheck(int) {
    cout << "OnPlayerCheck" << endl;
}

// 返り値をautoにもできる
auto Add(int a, int b) {
    return a + b;
}

// overload
int GetPlayerScore(int playerId) {
    return 100;
}

int GetPlayerScore() {
    return 0;
}

int GetPlayerScore(int playerId, int userId) {
    return 1000;
}

// C# ref, in, out
// ref
void MovePlayer(int& userId) {

}

// in
void PrintPlayer(const int& userId) {

}

// out
void PrintPlayer(int& playerId) {
    playerId = 10;
}

// static variables
int GetNextId() {
    // ローカル変数として宣言されたstatic varaibleは全呼び出して一つのインスタンスとなる
    static int id = 0;
    id++;
    return id;
}

// constexprについて
// コンパイル時に関数を実行して定数に置き換えてくれるやつ
constexpr int GetSquareOfSumUpTo(int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += i;
    }
    return sum * sum;
}

int main() {
    cout << GetNextId() << endl;
    cout << GetNextId() << endl;
    cout << GetNextId() << endl;

    // compile時に定数に置き換えられるので二つの行は同じ意味になる
    // ただし、引数がruntimeで決定する場合はruntimeの評価になる
    cout << GetSquareOfSumUpTo(5000) << endl;
    cout << 1020530960 << endl;
}