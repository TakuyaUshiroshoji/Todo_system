#ifndef TASK_H
#define TASK_H

#include <string>
#include <ctime>

class Task
{
public:
    Task(int id, const std::string &title, const std::tm &due_date);
    int getId() const;
    std::string getTitle() const;
    std::tm getCreateDate() const;
    std::tm getDueDate() const;
    bool getIsCompleted() const;
    void display() const;

private:
    int id;              // タスクID
    std::string title;   // タスクのタイトル
    std::tm create_date; // 作成日
    std::tm due_date;    // 期限(締切日)
    bool isCompleted;    // 完了フラグ
};

#endif // TASK_H