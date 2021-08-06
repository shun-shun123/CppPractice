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
}

int main() {
    simpleArray();
    multiDimensionalArray();
    stringSample();
}