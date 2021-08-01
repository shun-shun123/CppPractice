#include <iostream>
using namespace std;

// 変数宣言について
void declareVariables() {
    // C#と同様に宣言できる
    int x;
    // ここもC#と同様に、複数同時宣言できる
    int a,b,c;
    // C#との違いは未初期化の変数が作成できるところ
    cout << "===declareVariables===" << endl;
    cout << x << endl;
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
}

// 変数の初期化について
void initializeVariables() {
    int y = 0;
    int x = y;  // これは普通にコピー
    int a{}; // aは0で埋められる
    int b{123}; // この辺の{}を使った初期化はc++11系を指定してコンパイルする必要がある
    int c(123);
    cout << "===initializeVariables===" << endl;
    cout << "y: " << y << endl;
    cout << "x: " << x << endl;
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    cout << "c: " << c << endl;
}

// 型推論的なやつ
void typeDeduction() {
    auto x = 123;
    auto y{123};
    auto z(123);
    decltype(x) a = 123; // decltype check the type so a is int
    register int b = 123; // register keywordをつけることで、RAMではなくCPUレジスタにデータを置くことができる
    // ただし、c++17から非推奨になった
    cout << "===typeDeduction===" << endl;
    cout << "x: " << x << endl;
    cout << "y: " << y << endl;
    cout << "z: " << z << endl;
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
}

// pointer型の宣言
void pointerDeclaration() {
    // a,b,cは全てポインタ
    int* a;
    int * b;
    int *c;
    // xはポインタ y, zはint
    int * x, y, z;
    // d, fはポインタ eはint
    int *d, e, *f;
    cout << "===pointerDeclaration===" << endl;
    cout << "a: " << typeid(a).name() << endl;
    cout << "b: " << typeid(b).name() << endl;
    cout << "c: " << typeid(c).name() << endl;
    cout << "x: " << typeid(x).name() << endl;
    cout << "y: " << typeid(y).name() << endl;
    cout << "z: " << typeid(z).name() << endl;
    cout << "d: " << typeid(d).name() << endl;
    cout << "e: " << typeid(e).name() << endl;
    cout << "f: " << typeid(f).name() << endl;
}

void references() {
    // この辺の宣言はnon-nullable pointerのようなもので、初期化しないとコンパイルエラー
    // lvalueの宣言
    int aa = 123;
    int bb = 234;
    int cc = 345;
    int& a = aa;
    int & b = bb;
    int &c = cc;
    // rvalueの宣言
    int&& x = 123;
    int && y = 234;
    int &&z = 345;
    cout << "===references===" << endl;
    cout << "a: " << typeid(a).name() << endl;
    cout << "b: " << typeid(b).name() << endl;
    cout << "c: " << typeid(c).name() << endl;
    cout << "x: " << typeid(x).name() << endl;
    cout << "y: " << typeid(y).name() << endl;
    cout << "z: " << typeid(z).name() << endl;
}

int main() {
    declareVariables();
    initializeVariables();
    typeDeduction();
    pointerDeclaration();
    references();
}