#ifndef TASK_H
#define TASK_H

#include <string>
#include <ctime>

class Task
{
public:
    // Task();
    Task(int id, const std::string &title, const std::tm &due_date);
    int getId() const;
    std::string getTitle() const;
    std::tm getCreateDate() const;
    std::tm getDueDate() const;
    bool getIsCompleted() const;
    // int setId();
    // std::string setTitle();
    // std::tm setCreateDate();
    // std::tm setDueDate();
    // bool setIsCompleted();

private:
    int id_;              // タスクID
    std::string title_;   // タスクのタイトル
    std::tm create_date_; // 作成日
    std::tm due_date_;    // 期限(締切日)
    bool isCompleted_;    // 完了フラグ
};

#endif // TASK_H