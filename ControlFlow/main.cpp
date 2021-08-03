#include <iostream>

using namespace std;

// 基本的なifはC#と同じように使える
void ifState() {
    int flag = 0;
    if (flag == 0) {
        cout << "flag is 0" << endl;
    } else {
        cout << "flag is NOT 0" << endl;
    }
}

// C#とは異なり、ifの条件式の中で変数を宣言して、スコープの中でそれを使ったりできる
void initializationInsideIf() {
    if (int flag = 1; flag == 0) {
        cout << "flag is 0" << endl;
    } else {
        cout << "flag is " << flag << endl;
    }
}

// Goto構文もサポート
void goToSample() {
    int flag = 0;
    if (flag == 0) {
        cout << "flag is 0. terminate process."  << endl;
        goto ZeroFlag;
    }
    cout << "goToSample pass" << endl;

    ZeroFlag:
        cout << "Finished" << endl;
}

// 初期化した変数を飛び越えてgotoはできない
void skipInitializationWithGoTo() {
    goto Skip;
    int x; // これは未初期化なのでスキップできる
    // int x = 1; // これはスキップできない jump bypasses variable initialization
    Skip:
    cout << x << endl;
}

// switchの基本はC#と同じ
void switchSample() {
    int flag = 0;
    switch (flag) {
        case 0:
            cout << "flag is 0" << endl;
            break;
        case 1:
            cout << "flag is 1" << endl;
        default:
            cout << "not matched." << endl;
            break;
    }
}

// breakを書かずにスキップして行ったり、ifの括弧内での変数宣言みたいなことができる
// ただし、switchで判定できるのはintだけでパターンマッチみたいなことはできない
void noNeedBreakInSwitch() {
    switch (int flag = 0) {
        case 0:
            cout << "flag is 0" << endl;
        case 1:
            cout << "flag is 0 or 1" << endl;
        case 2:
            cout << "flag is 0 or 1 or 2" << endl;
            break;
        default:
            cout << "flag is not 0 and 1 and 2" << endl;
            break;
    }
}

// 三項演算子も使えるよ
void ternarySample() {
    int flag = 0;
    cout << "flag is " << (flag < 10 ? "less than" : "more than") << " 10" << endl; 
}

// 三項演算子の両方が同じ型である必要はなく、例外を投げたりできる
void ternaryThrowException() {
    int flag = 0;
    // int value = flag < 10 ? throw "flag is not more than 10" : 10;
}

// whileもかける
void whileSample() {
    int counter = 0;
    while (counter++ < 10) {
        if (counter % 2 == 0) {
            continue;
        }
        cout << counter << endl;
    }
}

// for文も同じ感じ
void forSample() {
    for (int i = 0; i < 10; i++) {
        if (i % 2 != 0) {
            continue;
        }
        cout << i << endl;
    }
}

int main() {
    ifState();
    initializationInsideIf();
    goToSample();
    skipInitializationWithGoTo();
    noNeedBreakInSwitch();
    ternarySample();
    ternaryThrowException();
    whileSample();
    forSample();
}