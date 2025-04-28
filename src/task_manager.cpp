#include <string>
#include <stdio.h>
#include <ctime>
#include <iostream>
#include <fstream>
#include <iomanip>

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

bool TaskManager::deleteTaskList()
{
    displayTaskList();
    std::cout << "削除するタスクIDを選択してください。\n";
    std::string input_task_id;
    std::getline(std::cin, input_task_id);
    int task_id{atoi(input_task_id.c_str())};

    bool result{deleteTask(task_id)};
    if (result)
    {
        std::cout << "タスクID" << task_id << "を削除しました。\n";
    }
    else
    {
        std::cout << "タスクID" << task_id << "は存在しません。 \n";
    }
    return result;
}

bool TaskManager::deleteTask(const int task_id)
{
    for (auto it = tasks_.begin(); it != tasks_.end(); ++it)
    {
        if (it->getId() == task_id)
        {
            tasks_.erase(it);
            return true;
        }
    }
    return false;
}

void TaskManager::saveTasks(const std::string &file_name) const
{
    std::ofstream file(file_name); // 書き込み用にファイルを開く
    if (!file)
    {
        std::cerr << "ファイルを開けませんでした" << std::endl;
        return;
    }

    for (const auto &task : tasks_)
    {
        file << task.getId() << ","
             << task.getTitle() << ","
             << (task.getCreateDate().tm_year + 1900) << "-"
             << (task.getCreateDate().tm_mon + 1) << "-"
             << task.getCreateDate().tm_mday << ","
             << (task.getDueDate().tm_year + 1900) << "-"
             << (task.getDueDate().tm_mon + 1) << "-"
             << task.getDueDate().tm_mday << ","
             << task.getIsCompleted() << "\n";
    }
}

void TaskManager::loadTasks(const std::string &file_name)
{
    std::ifstream file(file_name); // 読み込み用にファイルを開く
    if (!file)
    {
        std::cerr << "ファイルを開けませんでした" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line))
    {
        std::stringstream line_stream(line);
        std::string id_str, title, create_date_str, due_date_str, is_completed_str;

        std::getline(line_stream, id_str, ',');
        std::getline(line_stream, title, ',');
        std::getline(line_stream, create_date_str, ',');
        std::getline(line_stream, due_date_str, ',');
        std::getline(line_stream, is_completed_str, ',');

        int id{std::stoi(id_str)};
        std::tm create_date;
        DateFormatter::stringToTime(create_date_str, create_date);

        std::tm due_date;
        DateFormatter::stringToTime(due_date_str, due_date);

        bool is_completed{std::stoi(is_completed_str)};

        Task task(id, title, create_date, due_date, is_completed);
        tasks_.push_back(task);
    }
}