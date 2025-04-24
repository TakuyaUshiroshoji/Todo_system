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

int Task::getId() const { return id_; }
std::string Task::getTitle() const { return title_; }
std::tm Task::getCreateDate() const { return create_date_; }
std::tm Task::getDueDate() const { return due_date_; }
bool Task::getIsCompleted() const { return isCompleted_; }