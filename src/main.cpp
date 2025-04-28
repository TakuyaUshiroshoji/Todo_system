#include <iostream>
#include <limits>

#include "selection_screen.h"
#include "task_manager.h"

int main()
{
    SelectionScreen select;
    TaskManager task_manager;
    std::string file_name{"tasks.txt"};
    // 起動時にタスクを読み込み
    task_manager.loadTasks(file_name);
    int choice{0};

    while (true)
    {
        choice = select.displayChoice();
        // std::cin >> choice のあとに残った改行を捨てる
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice)
        {
        case 1:
            if (task_manager.addTask())
            {
                task_manager.saveTasks(file_name);
            }
            break;
        case 2:
            task_manager.displayTaskList();
            break;
        case 3:
            if (task_manager.deleteTaskList())
            {
                task_manager.saveTasks(file_name);
            }
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