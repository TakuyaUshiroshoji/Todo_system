#include <iostream>

#include "selection_screen.h"

int SelectionScreen::displayChoice()
{
    std::cout << "---------------- \n";
    std::cout << "選択してください \n";
    std::cout << "---------------- \n";
    std::cout << "1.タスクを追加 \n";
    std::cout << "2.今日のタスクを表示 \n";
    std::cout << "3.期限切れのタスクを表示 \n";
    std::cout << "4.すべてのタスクを表示 \n";
    std::cout << "5.タスクを削除 \n";
    std::cout << "6.タスクを編集（名前・期限） \n";
    std::cout << "7.完了済みタスクを表示 \n";
    std::cout << "8.終了 \n";
    std::cin >> choice_;
    return choice_;
}