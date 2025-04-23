#include <ctime>
#include <iostream>

#include "task.h"
#include "date_formatter.h"

Task::Task(int id, const std::string &title, const std::tm &due_date)
    : id_(id), title_(title), due_date_(due_date), isCompleted_(false)
{
    std::time_t now = std::time(nullptr);
    create_date_ = *std::localtime(&now);
}

void Task::display() const
{
    std::cout << "ID: " << id_
              << " | 内容: " << title_
              << " | 状態: " << (isCompleted_ ? "完了" : "未完了")
              << " | 作成日: " << DateFormatter::timeToString(create_date_) // formatterかける
              << " | 期限: " << DateFormatter::timeToString(due_date_)      // formatterかける
              << "\n";
}