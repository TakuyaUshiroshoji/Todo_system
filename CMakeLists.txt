cmake_minimum_required(VERSION 3.10)
project(MyProject)

set(CMAKE_CXX_STANDARD 17)

# ヘッダーとソースのディレクトリ指定
include_directories(inc)

# メインアプリのビルド
add_executable(MyProject
    src/main.cpp
    src/date_formatter.cpp
    src/selection_screen.cpp
    src/task.cpp
    src/task_manager.cpp
)

# ================================
# Google Test を使ったテスト設定
# ================================
enable_testing()

# Google Test を追加
add_subdirectory(googletest)

# テスト対象コードのソースもリンク
add_executable(DateFormatterTest
    test/date_formatter_test.cpp
    src/date_formatter.cpp
)

# ヘッダーファイルのディレクトリも追加 ← ここ！
target_include_directories(DateFormatterTest PRIVATE inc)

# GoogleTest をリンク
target_link_libraries(DateFormatterTest gtest gtest_main)

# テストとして登録
add_test(NAME DateFormatterTest COMMAND DateFormatterTest)