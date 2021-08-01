#include <iostream>
#include "math.h"
// ディレクトリ構造にも対応してるのでこんな感じのincludeも可能
#include "mylib/hello.h"

using namespace std;

int main() {
    cout << "Hello, World!" << endl;
    int a = 1;
    int b = 1;
    auto sum = Add(a, b);
    cout << sum << endl;
    return 0;
}