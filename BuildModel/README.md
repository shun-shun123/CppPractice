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
