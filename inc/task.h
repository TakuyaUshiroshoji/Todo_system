#ifndef TASK_H
#define TASK_H

#include <string>

class Task {
private:
    int id;               // タスクID
    std::string title;    // タスクのタイトル
    std::tm create_date;  // 作成日
    std::tm due_date;     // 期限(締切日)
    bool isCompleted;     // 完了フラグ
public:
    // タスク一覧表示
    void displayTask() const;
};

#endif // TASK_H