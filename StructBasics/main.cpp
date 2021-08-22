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

// 合計で8byte確保する
struct Padded {
    int8_t a;   // これは1byte確保する
                // CPUのアーキテクチャにもよるけど、例えばpadding3byte確保される
    int32_t b;  // 4byte確保される
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

// 続きはLayoutについて学んでいく
// C++には"standard layout"というものがあり、同じデータメンバーは同じようにメモリ上に配置される(例外もあるが)
struct Vec3Sample
{
    float x;
    float y;
    float z;
};

struct Quat
{
    // Vec3と同じメモリレイアウトでスタート
    float x;
    float y;
    float z;

    float w;
};

void reinterpretStruct() {
    cout << "=====reinterpretStruct=====" << endl;
    Vec3Sample vec;
    Vec3Sample* pVec = &vec;
    Quat* pQuat = (Quat*)pVec;

    // 次の操作は安全
    pQuat->x = 1;
    pQuat->y = 2;
    pQuat->z = 3;

    // 次の操作は危険. Vec3Sampleはwまでのメモリレイアウトを確保していない
    pQuat->w  = 4;
    cout << "x: " << pQuat->x << endl;
    cout << "y: " << pQuat->y << endl;
    cout << "z: " << pQuat->z << endl;
    cout << "w: " << pQuat->w << endl;
}

struct BitPlayer {
    bool IsAlive : 1;
    uint8_t Lives : 3;
    uint8_t Team : 2;
    uint8_t WeaponID : 2;
};

struct PlayerScore {
    static int32_t HighScore;
};

void printPlayerScore() {
    cout << "=====printPlayerScore=====" << endl;
    cout << "PlayerScore::HighScore " << PlayerScore::HighScore << endl;
}

int main() {
    useStructSample();
    anonymousStruct();
    reinterpretStruct();
    printPlayerScore();
}