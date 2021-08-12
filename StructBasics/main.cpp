#include <iostream>

using namespace std;

// まずは宣言
struct Vec3;

// 次に定義
struct Vec3 {
    // structのメンバ変数宣言時に初期化もできる
    float x = 0;
    float y{0};
    float z = 0;
};

// structはそのサイズをコンパイル時に確定できないといけないため、宣言だけして定義をしていない段階で使ったらコンパイルエラーが起きる
// これはC++のコンパイラがソースコードの上から順番に読んでいっているため。
// ただし、それを指すポインタなら使える（ポインタならサイズが判明している必要はなくて、それがある場所だけ刺せばいいので）

void useStructSample();
void printVecOut(Vec3);

void useStructSample() {
    cout << "=====<useStructSample=====" << endl;
    Vec3 vec;
    vec.x = 1;
    vec.y = 2;
    vec.z = 3;
    printVecOut(vec);

    Vec3 vec2;
    printVecOut(vec2);
}

void anonymousStruct() {
    // 匿名のstructも作れる
    struct {
        const char16_t* Name;
        int32_t Year;
    } moonMission;

    moonMission.Name = u"Apollo 11";
    moonMission.Year = 1969;
    cout << "moonMission: (" << moonMission.Name << ": " << moonMission.Year << ")" << endl;
}

void printVecOut(Vec3 vec) {
    cout << "vec: (" << vec.x << ", " << vec.y << ", " << vec.z << ")" << endl;
}

続きはLayoutについて学んでいく

int main() {
    useStructSample();
    anonymousStruct();
}