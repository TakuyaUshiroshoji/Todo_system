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
    int addTask();
    void deleteTask();

private:
    std::vector<Task> tasks;
    int next_id;
};

#endif // TASK_MANAGER_H