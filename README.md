CSV loader for C++
====

# Overview
This is a C++ CSV file parser for numerical data.

You can access the CSV file as an Eigen matrix object.

This class is compatible with int, double, and flowt type data.

I will continue to update this class to be more convinience, e.g. file exporting. Please feel free to pull request if you want to add new features.

## Japanese

C++でCSVファイルを読み込むためのクラスを作成しました．

カンマで区切られたCSVファイルのみ対応しています．タブはダメです．

int, double, float型に対応していますので，オブジェクトを作成するときに，指定してください．他の型は未定義です，このクラスは，計算結果や計算用のパラメータを読み込んだりするために作ったので，文字データに対応する予定は今の所ありません，悪しからず．

読み込んだデータは，要素一つずつアクセスすることもできますし，Eigenの行列として取り出すこともできます．

読み込みだけではなく，ファイルの書きだしなど，もっと便利になるようにアップデートしていけたらと思います．プルリクエストなどはお気軽にどうぞ（むしろお願いします）．

なお，このクラスを用いたことにより発生した問題などの責任は一切とりませんので，自己責任でお願いいたします．

# Requirements
- Eigen: C++ linear algebra library

# Usage

You only have to put cppcsv.hpp in your project directory and set the include path for your compiler.

```cpp
#include "cppcsv.hpp"
```

## Instanciate and load a CSV file

```cpp
// Instanciate
// You can choose tye type from int, double, and float.
// Other type is not defined now.
csv<int> data;

// Load a CSV file.
// You have to define row size and column size of the data
data.load("test_w.csv", 5, 10);
```

## Access the data

You can access each elements of the data.
```cpp
// You have to set arguments of the accessor to find row and colmun
// obj(row, col);
int i = data(3, 4);
```

You can also acces the data as Eigen matrix.
```cpp
Eigen::Matrix<int, Eigen::Dynamic, Eigen::Dynamic> mat = data.get_asEigen();
```

Get data as an std::vector.
```cpp
// Get data as a one dimension std::vector.
vector<int> v = data.get_asVector1d();
// Get data as a two dimension std::vector.
vector<vector<int>> v2 = data.get_asVector2d();
```