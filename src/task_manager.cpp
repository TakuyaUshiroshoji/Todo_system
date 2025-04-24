#include <string>
#include <ctime>
#include <iostream>

#include "task_manager.h"
#include "date_formatter.h"
#include "task.h"

TaskManager::TaskManager()
    : next_id_(1) {}

bool TaskManager::addTask()
{
    std::string title;
    std::string input_due_date;
    std::tm output_due_date;

    std::cout << "タイトルを入力してください: \n";
    std::getline(std::cin, title);
    std::cout << "期限を YYYY-MM-DD 形式で入力してください: \n";
    std::getline(std::cin, input_due_date);

    // 入力された期限の日付文字列を日付構造体に変換
    if (!DateFormatter::stringToTime(input_due_date, output_due_date))
    {
        std::cout << "日付の形式が正しくありません。\n";
        return false;
    }
    Task new_task(next_id_, title, output_due_date);
    tasks_.push_back(new_task);
    next_id_++;
    std::cout << "タスクが追加されました。\n";
    return true;
}

void TaskManager::displayTaskList() const
{
    std::cout << "タスク一覧を表示\n";
    for (auto t : tasks_)
    {
        std::cout << "ID" << t.getId()
                  << "| タイトル" << t.getTitle()
                  << "| 期限" << DateFormatter::timeToString(t.getDueDate())
                  << "| 完了:" << (t.getIsCompleted() ? "はい" : "いいえ")
                  << "| 作成日" << DateFormatter::timeToString(t.getCreateDate())
                  << std::endl;
    }
}

// bool deleteTaskList()
// {
//     std::cout << "削除するタスクIDを選択してください。\n";
// }