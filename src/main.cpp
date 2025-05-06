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
        // 1.タスクを追加
        case 1:
            if (task_manager.addTask())
            {
                task_manager.saveTasks(file_name);
            }
            break;
        // 2.今日のタスクを表示
        case 2:
            break;
        // 3.期限切れのタスクを表示
        case 3:
            break;
        // 4.すべてのタスクを表示
        case 4:
            task_manager.displayTaskList();
            break;
        // 5.タスクを削除
        case 5:
            if (task_manager.deleteTaskList())
            {
                task_manager.saveTasks(file_name);
            }
            break;
        // 6.タスクを編集（名前・期限）
        case 6:
            break;
        // 7.完了済みタスクを表示
        case 7:
            break;
        // 8.終了
        case 8:
            std::cout << "終了します。\n";
            return 0;
        default:
            std::cout << "無効な選択です。\n";
            break;
        }
    }
}