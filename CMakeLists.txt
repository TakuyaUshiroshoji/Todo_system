cmake_minimum_required(VERSION 3.10)  # 最低バージョン指定
project(MyProject)                    # プロジェクト名

set(CMAKE_CXX_STANDARD 17)            # C++のバージョン

# ヘッダーファイルのディレクトリ
include_directories(inc)

# 実行ファイルとソースファイル
add_executable(MyProject
    src/main.cpp
    src/dateformatter.cpp
    src/selection_screen.cpp
    # src/task.cpp
)