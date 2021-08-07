#include <iostream>

using namespace std;

void simpleArray() {
    cout << "=====simpleArray======"  << endl;
    // 3のサイズを持つ配列を定義するが、それぞれの値は未定義状態
    // これはint a0, a1, a2;を定義するのと同義でC#のようにLengthなどはない。ローカル変数として宣言すればstackallocと同様の挙動になる
    int a[3];
    a[0] = 123;

    cout << a[0] << endl;

    int* p = a;
    cout << "*p: " << *p << endl;
    cout << "*p+1: " << *(p + 1) << endl;

    // 配列の初期化　
    int b[3] = {123, 456, 789};
    cout << b[0] << ", " << b[1] << ", " << b[2] << endl;

    // 一部分を定義するならコンマが必要
    int c[3] = {123, 456,};
    cout << c[0] << ", " << c[1] << endl;
}

void multiDimensionalArray() {
    int a[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int (*p)[3] = a;
    int* pp = *p;
    for (int i = 0; i < 6; i++) {
        cout << pp[i] << ", ";
    }
    cout << endl;

    int b[2][3] = { {1, 2, 3}, {4, 5, 6} };
    int* firstRow = b[0];
    cout << firstRow[0] << ", " << firstRow[1] << ", " << firstRow[2] << endl;
}

// C#だとSystem.StringというクラスでGC対象として作成できる文字列がある
// C++の場合はnull-terminatedのchar配列になる
void stringSample() {
    cout << "=====stringSample=====" << endl;

    // char[6]の配列として扱える
    // h e l l o 0
    const char hello[] = "hello";

    // 他の配列と同様に、ポインタに変換できる
    const char* p = hello;

    for (int i = 0; i < 6; i++) {
        cout << p[i];
    }
    cout << endl;

    // char[]は上書きできない
    // hello[0] = 'a';
}

void variousStrings() {
    cout << "=====variousStrings=====" << endl;
    // ASCII 
    const char chr[] = "hello";

    // Wide character string
    const wchar_t wChr[] = L"hello";

    // UTF-8 string
    const char8_t utf8Chr[] = u8"hello";

    // UTF-16
    const char16_t utf16Chr[] = u"hello";

    // UTF-32
    const char32_t utf32Chr[] = U"hello";
}

void concatenateStrings() {
    // 文字列連結に+はいらない
    const char msg[] = "Hello, " "World!";

    cout << msg << endl;
}

// 適当な関数なので実装は気にしない
int getHealth() {
    return 100;
}

int getLives() {
    return 2;
}

// 関数ポインタについて
void functionPointer() {
    // 関数へのポインタを持つことができる
    // この場合は、引数なしのメソッドに対するポインタを持つので宣言もこんな感じでできる
    int (*p)() = getHealth;

    int health = p();

    cout << "health: " << health << endl;
}

// 関数ポインタを配列として持つこともできる
void functoinPointersArray() {
    int (*p[])() = { getHealth, getLives};
    int health = p[0]();
    int lives = p[1]();

    cout << "health: " << health << endl;
    cout << "lives: " << lives << endl;
}

int main() {
    simpleArray();
    multiDimensionalArray();
    stringSample();
    concatenateStrings();
    functionPointer();
    functoinPointersArray();
}