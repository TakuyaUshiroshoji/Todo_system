#include <iostream>

#include "selection_screen.h"

int SelectionScreen::displayChoice()
{
    std::cout << "---------------- \n";
    std::cout << "選択してください \n";
    std::cout << "---------------- \n";
    std::cout << "1.タスクを追加 \n";
    std::cout << "2.タスクを表示 \n";
    std::cout << "3.タスクを削除 \n";
    std::cout << "4.終了 \n";
    std::cin >> choice_;
    return choice_;
}