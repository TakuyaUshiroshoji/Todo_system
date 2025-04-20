#include <iostream>
#include "selection_screen.h"
// #include "task.h"

int main()
{
    SelectionScreen select;
    int choice;
    choice = select.display_choice();
    std::cout << "選択されたのは" << choice << "です\n";
    // Task task;
    switch (choice)
    {
    case 1:
        break;
    case 2:
        // task.displayTask();
        break;
    case 3:
        break;
    case 4:
        std::cout << "終了します。\n";
        break;
    default:
        std::cout << "無効な選択です。\n";
        break;
    }
}