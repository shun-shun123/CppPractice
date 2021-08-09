#include <iostream>

using namespace std;

void referenceSample() {
    cout << "=====referenceSample=====" << endl;
    int x = 123;
    // pointerと似ているが、*の代わりに&で型宣言している
    // LValue referenceは宣言時に初期化しないとコンパイルエラーになる
    int& r = x; // reference
    cout << "x: " << x << endl;
    // 値を参照したい場合は変数名をそのまま記述する
    cout << "r: " << r << endl;

    // lvalue referenceは何か名前付きのものを参照するので定数は無理
    // non-const lvalue reference to type int cannot bind to a temprary of type int
    // int& lr = 123;
    // cout << "lr: " << lr << endl;
}

// lValue reference is just alias
void aliasSample() {
    cout << "=====aliasSample=====" << endl;
    // lvalue referenceはアライアスのようなもの
    int x = 123;
    int y = 456;
    int& r = x;
    // 下記のコードはこれと同じ
    // x = y; yが読み出されてxに書き込まれる
    // rはあくまでxのアライアスに過ぎないので、xの値が書き換えられる
    r = y;

    cout << "x: " << x << endl;
    cout << "y: " << y << endl;
    cout << "r: " << r << endl;
}

// reference to reference?
void refToRef() {
    cout << "=====refToRef======" << endl;
    int x = 123;
    // r1はxへのアライアスとなる
    int& r1 = x;

    // r2も同じくxへのアライアスとなる
    int& r2 = r1;

    x = 456;
    cout << "x: " << x << endl;
    cout << "r1: " << r1 << endl;
    cout << "r2: " << r2 << endl;
}

void initializeWays() {
    cout << "=====initializeWays=====" << endl;
    int x = 123;
    int& r1 = x;
    int& r2(x);
    int& r3 = {x};
    int& r4{x};
    cout << "x: " << x << endl;
    cout << "r1: " << r1 << endl;
    cout << "r2: " << r2 << endl;
    cout << "r3: " << r3 << endl;
    cout << "r4: " << r4 << endl;
}

// アライアスなので、こんな感じで引数にわたってきた値を更新することもできる
// C#でいうref structみたいな渡し方かな
void incrementRefValue(int& refValue) {
    cout << "=====incrementRefValue=====" << endl;
    refValue++;
}

// 関数への参照として引数に渡せば、C#のFunc<int, bool>みたいなこともできる
int findIndex(int array[5], bool (&predict)(int)) {
    for (int i = 0; i < 5; i++) {
        if (predict(array[i])) {
            return i;
        }
    }
    return -1;
}

bool isEven(int val) {
    return (val & 1) == 0;
}

bool isOdd(int val) {
    return (val & 1) == 1;
}

int main() {
    referenceSample();
    aliasSample();
    refToRef();
    initializeWays();
    int x = 100;
    incrementRefValue(x);
    cout << "x: " << x << endl;
    cout << "=====findIndex=====" << endl;
    int array[5] = {1, 2, 3, 4, 5};
    int index = findIndex(array, isEven);
    cout << "index: " << index << endl;

    cout << "=====choise predict method=====" << endl;
    bool (&predict)(int) = false ? isEven : isOdd;
    index = findIndex(array, predict);
    cout << "index: " << index << endl;
}