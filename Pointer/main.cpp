#include <iostream>

using namespace std;

void pointerSample() {
    int x = 123;

    // int*でintへのポインターを宣言できる
    // xのアドレスは&xで取得できる
    int* p = &x;

    // *pでポインターの指す値を取得できる
    cout << *p << endl;

    // ポインターの指す値に直接書き込むこともできる
    *p = 456;
    cout << *p << endl;
}

// ポインターのポインターみたいなやつができる
void multipleLevelPointer() {
    int x = 123;
    int* p = &x;
    int** pp = &p;

    cout << "=====multipleLevelPointer=====" << endl;

    cout << "x: " << x << endl;
    cout << "*p: " << *p << endl;
    cout << "**pp: " << **pp << endl;

    int y = 1000;
    *pp = &y;   // *pp の指す場所をxからyに変える
    **pp = 2000; // *pp が指している場所yの値を変更
    cout << "y: " << y << endl;
    cout << "**pp: " << **pp << endl;
}

// なんでもさせるvoid*の説明
void voidPointer() {
    cout << "=====voidPointer=====" << endl;

    int x = 123;

    // void* はどの型のポインタにもなれる
    void* pVoid = &x;

    // void*はキャストして使える（実行時のキャストになる）
    int* pInt = (int*)pVoid;
    cout << "pInt: " << *pInt << endl;

    float* pFloat = (float*)pVoid;
    *pFloat = 3.14; // 実はintにfloatを入れようとしている. bit的には代入できるので値が壊れてしまう
    cout << "x: " << x << endl;
}

void nullPointer() {
    // nullptrは全てのポインタと互換性のある型。ただし整数値としては扱えない
    int* p1 = nullptr;
    // NULLは基本的に0と定義されたもの。整数値としても扱える　
    int* p2 = NULL;
    // 整数値0
    int* p3 = 0;
}


int main() {
    pointerSample();
    multipleLevelPointer();
    voidPointer();
}