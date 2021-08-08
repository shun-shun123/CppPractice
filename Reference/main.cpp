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
}

lValue Referenceの途中まで読んでる

int main() {
    referenceSample();
}