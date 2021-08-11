#include <iostream>

using namespace std;

// C#の[Flag]みたいな属性は使えないので、自力でビット演算はするしかない
enum Color : unsigned int {
    Red = 0xff0000,
    Green = 0x00ff00,
    Blue = 0x0000ff
};

// enumは0から始まる整数値としても扱える
// int, unsigned int, long, unsigned long, long long, unsigned long longから自動的にコンパイラが選択する
// どれにも当てはまらないサイズの場合は、エラーを起こす
// 明示的に指定することも可能
enum Prime {
    One = 1,
    Two,
    Three,
    Five = 5
};

// scoped enumerationはこのスコープ内でしか使えない
// 整数値変換もintのみ
// Number::Firstみたいにしか描けない
// 暗黙的な数値へのキャストはコンパイルエラー
enum class Number {
    First,
    Second,
}

void printEnumColor() {
    cout << "=====printEnumColor=====" << endl;
    // Colorのスコープ内なのでRedを直接参照できる
    cout << "Red: " << Red << endl;
    // C++のscope resolutionを使ってこういう書き方もできる
    cout << "Green: " << Color::Green << endl;

    cout << "One: " << One << endl;
    cout << "Five: " << Five << endl;
    // int型の変数にそのまま代入できる
    int two = Two;
    cout << "two: " << two << endl;
}

void castPractice() {
    cout << "=====castPractice=====" << endl;

    // enumはintなどの数値型に明示的なキャストもできる
    // ただし、サイズを超えていた場合などはundefinedな挙動となる
    int one = (int)One;
    // 逆もまた然り
    Prime prime = (Prime)1;

    cout << "one: " << one << endl;
    cout << "prime: " << prime << endl;
}

void passByValue(Color color) {
}

int main() {
    printEnumColor();
    castPractice();
    passByValue(Red);   // これは大丈夫
    // passByValue(0xff0000); // これはコンパイルエラー
}