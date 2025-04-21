#include <iostream>
#include "selection_screen.h"
#include "task_manager.h"

int main()
{
    SelectionScreen select;
    int choice;
    choice = select.displayChoice();
    std::cout << "選択されたのは" << choice << "です\n";

    // switch (choice)
    // {
    // case 1:
    //     TaskManager task_manager;
    //     task_manager.addTask();
    //     break;
    // case 2:
    //     // task.displayTask();
    //     break;
    // case 3:
    //     break;
    // case 4:
    //     std::cout << "終了します。\n";
    //     break;
    // default:
    //     std::cout << "無効な選択です。\n";
    //     break;
    // }
}