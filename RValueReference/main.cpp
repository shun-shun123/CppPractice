/*
    lvalue reference/rvalue referenceとC#の関係性について
    lvalue referenceはいわゆるC#のrefに近い
    値のエイリアスとして機能している. ただ、C++とは異なり、C#では関数に対してrefをつけることはできない
    
*/

#include <iostream>

using namespace std;

void sampleRValueReference() {
    // int&&と「&」を二つで宣言した型に対しては、名前を持たない値をそのまま参照させることができる
    // 5という値の生存期間はrの生存期間と一致する（rがnullを参照しないようにするため）
    int&& r = 5;

    // 123はrvalueだが、xに書き込まれた直後で生存期間は終了する
    int x = 123;

    cout << "r: " << r << endl;
    cout << "x: " << x << endl;

    // 参照先を6に書き換える
    r = 6;
    cout << "r: " << r << endl;

    // 5という数字の定義が変わったわけではない
    cout << "5: " << 5 << endl;
}

void initializeWays() {
    cout << "=====initializeWays=====" << endl;
    int&&r1 = 5;
    int&& r2(5);
    int&& r3 = {5};
    int&& r4{5};

    cout << "r1: " << r1 << endl;
    cout << "r2: " << r2 << endl;
    cout << "r3: " << r3 << endl;
    cout << "r4: " << r4 << endl;
}

// 関数を抜けたら生存期間が終了するもの（主にstructなど）をrvalue referenceとして返すと不安定な挙動の原因となりやすい
int&& danglingSample() {
    cout << "=====danglingSample=====" << endl;
    return 5;
}

// rvalue referenceとlvalue refenreceの互換性
void rvalueRefAndlvalueRef() {
    int x = 123;
    int& xlr = x;
    // これはできない. rvalue reference to type int cannnot bind to lvalue of type int
    // int&& xrr = x;

    // これもできない. non-const lvalue reference to type int cannnot bind to a temporary of type int
    // int& ylr = 123;
    int&& yrr = 123;
    int& ylrr = yrr;
}

int main() {
    sampleRValueReference();
    initializeWays();
    cout << "dangling: " << danglingSample() << endl;
    rvalueRefAndlvalueRef();
}