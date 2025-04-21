#include <ctime>
#include <iostream>

#include "task.h"
#include "dateformatter.h"

Task::Task(int id, const std::string &title, const std::tm &due_date)
    : id(id), title(title), due_date(due_date), isCompleted(false)
{
    std::time_t now = std::time(nullptr);
    create_date = *std::localtime(&now);
}

void Task::display() const
{
    std::cout << "ID: " << id
              << " | 内容: " << title
              << " | 状態: " << (isCompleted ? "完了" : "未完了")
              << " | 作成日: " << DateFormatter::timeToString(create_date) // formatterかける
              << " | 期限: " << DateFormatter::timeToString(due_date)      // formatterかける
              << "\n";
}