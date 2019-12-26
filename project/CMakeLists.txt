cmake_minimum_required(VERSION 3.0)
# コンパイルに必要なソースコードを取得
file(GLOB common_src ../../common_objects/src/*.cpp)
file(GLOB my_src ../src/*.cpp)
# インクルードパスの設定
include_directories(./eigen)
#include_directories(../../common_objects/lib/cereal-1.2.2/include)
include_directories(../head)
# コンパイラへのオプション
set(CMAKE_CXX_FLAGS "-std=c++0x -O3")
# コンパイル対象コードと出力ファイル名
add_executable(main ${common_src} ${my_src})

# OpenCVに必要(Linuxの場合)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(main ${OpenCV_LIBS})