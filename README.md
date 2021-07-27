CSV loader for C++
====

## 概要
C++でCSVファイルを読み込むためのクラスです．Eigenは必要ですが，headerファイルを読み込むだけで使用できます．数値の並んだCSVファイルを読み込み，std::vectorやEigenで扱えるようにするために作りました．

**扱える型**
- int
- float
- double

読み込んだデータへの取得方法は以下の通りです．
- 行と列の番号で単一の要素を取得
- std::vectorの2次元配列として取得
- Eigenの行列として取得

## 今後
必要に応じてアップデートしていきます．IssueやPull Requestなど歓迎です．

## メソッド
| メソッド | 説明 |
| --- | ---|
| csv() | コンストラクタ |
| csv(const string& fileName) | コンストラクタで読み込みファイル指定 |
| load(const string& fileName) | CSVファイル読み込み |
| show() | 読み込んだものを表示 |
| get_rowsize() | 行数を取得 |
| get_colsize() | 列数を取得 |
| operator()(const int row, const int col) | 行番号，列番号を指定して値を取得 |
| get_asEigen() | Eigen::Matrixでデータ全てを取得 |
| get_asVector1d() | 1次元std::vectorとしてデータ全てを取得 |
| get_asVector2d() | 2次元std::vectorとしてデータ全てを取得 |

## お断り
全てを完全にテストしているわけではありませんので，バグなどあるかもしれません．その時はぜひissueお願いします．

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
// You shouldn't set data sizes. But in this case, the loading may take long time.
data.load("test_w.csv");
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