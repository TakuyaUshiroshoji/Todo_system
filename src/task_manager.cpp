#include <string>
#include <ctime>
#include <iostream>

#include "task_manager.h"
#include "dateformatter.h"
#include "task.h"

int TaskManager::addTask()
{
    std::string title;
    std::string input_due_date;
    std::tm output_due_date;

    std::cout << "タイトルを入力してください: ";
    std::getline(std::cin, title);
    std::cout << "期限を YYYY-MM-DD 形式で入力してください: ";
    std::getline(std::cin, input_due_date);

    // 入力された期限の日付文字列を日付構造体に変換
    if (!DateFormatter::stringToTime(input_due_date, output_due_date))
    {
        std::cout << "日付の形式が正しくありません。\n";
        return -1;
    }

    // タスクの作成
    Task new_task(next_id, title, output_due_date);

    tasks.push_back(new_task);

    next_id++;

    std::cout << "タスクが追加されました。\n";
    return 0;
}