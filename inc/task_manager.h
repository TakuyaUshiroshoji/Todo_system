#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include <vector>

#include "task.h"

///
/// @brief TaskManagerクラスはタスク一覧
///
/// 複数のタスクを持ち、追加・削除・表示などを制御する
///
class TaskManager
{
public:
    TaskManager();
    bool addTask();
    void displayTaskList() const;
    bool deleteTaskList();
    bool deleteTask(int task_id);
    void saveTasks(const std::string &file_name) const;
    void loadTasks(const std::string &file_name);
    bool completeTask(); // 仮 タスクを完了するメソッド

private:
    std::vector<Task> tasks_;
    int next_id_;
};

#endif // TASK_MANAGER_H