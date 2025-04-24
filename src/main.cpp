#include <iostream>
#include "selection_screen.h"
#include "task_manager.h"
#include <limits>

int main()
{
    SelectionScreen select;
    TaskManager task_manager;
    int choice{0};

    while (true)
    {
        choice = select.displayChoice();
        // std::cin >> choice のあとに残った改行を捨てる
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "選択されたのは" << choice << "です\n";

        switch (choice)
        {
        case 1:
            task_manager.addTask();
            break;
        case 2:
            task_manager.displayTaskList();
            break;
        case 3:
            std::cout << "未実装";
            break;
        case 4:
            std::cout << "終了します。\n";
            return 0;
        default:
            std::cout << "無効な選択です。\n";
            break;
        }
    }
}