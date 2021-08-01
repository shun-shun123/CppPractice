# 複数cppファイルのコンパイル方法について
## 分割コンパイル
- main.cpp
- math.cpp
- math.h

の3ファイルがある場合、

```
g++ -c main.cpp -o main.o
g++ -c math.cpp -o math.o
g++ main.o math.o -o out
./out
```

で分割コンパイル→リンクを行い実行可能なバイナリを作成できる

## 一括コンパイル
```
g++ -o out main.cpp math.cpp
```

## 分割コンパイルやMakefileについて参考になったサイト
- [分割コンパイルについて](http://sa.eei.eng.osaka-u.ac.jp/eeisa003/tani_prog/HOWTOprogC/split.htm)

# preprocessorについて
コンパイルのメインフェーズ前に行われる処理を定義できる

```
#include "math.h"
```

の場合は、math.cppがディレクトリに存在するかをチェックし、見つからなければC++ standard libraryのなかで探しにいく。
→もしどこにも見つからなければコンパイルエラーとなる

# ODR(One Definition Rule)について
こんな感じのコードがあったとして、

```cpp
// math.h
int Add(int a, int b);
float PI = 3.14f;
 
 
// vector.h
#include "math.h"
float Dot(float aX, float aY, float bX, float bY);
 
 
// user.cpp
#include "math.h"
#include "vector.h"
int AddThree(int a, int b, int c)
{
    return Add(a, Add(b, c));
}
bool IsOrthogonal(float aX, float aY, float bX, float bY)
{
    return Dot(aX, aY, bX, bY) == 0.0f;
}
```

user.cppのプリプロセッサーの挙動についてみていくと、まずは　`#include "math.h"`が差し替えられて

```cpp
int Add(int a, int b);
float PI = 3.14f;
#include "vector.h"
int AddThree(int a, int b, int c)
{
    return Add(a, Add(b, c));
}
bool IsOrthogonal(float aX, float aY, float bX, float bY)
{
    return Dot(aX, aY, bX, bY) == 0.0f;
}
```

となる。

次に、`#include "vector.h`を差し替えて

```cpp
int Add(int a, int b);
float PI = 3.14f;
#include "math.h"
float Dot(float aX, float aY, float bX, float bY);
int AddThree(int a, int b, int c)
{
    return Add(a, Add(b, c));
}
bool IsOrthogonal(float aX, float aY, float bX, float bY)
{
    return Dot(aX, aY, bX, bY) == 0.0f;
}
```

こうなる。

最後に、`#include "math.h"`を差し替えるので

```cpp
int Add(int a, int b);
float PI = 3.14f;
int Add(int a, int b);
float PI = 3.14f;
float Dot(float aX, float aY, float bX, float bY);
int AddThree(int a, int b, int c)
{
    return Add(a, Add(b, c));
}
bool IsOrthogonal(float aX, float aY, float bX, float bY)
{
    return Dot(aX, aY, bX, bY) == 0.0f;
}
```

こうなる。
Add関数の定義についての重複は問題ないが、PIの宣言についてはODRを侵害するのでコンパイルエラーとなる

## これの解決方法
### include guard
```cpp
#if (!defined MATH_H)
#define MATH_H
 
int Add(int a, int b);
float PI = 3.14f;
 
#endif
```