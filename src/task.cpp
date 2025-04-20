#include <iostream>

#include "task.h"
#include "dateformatter.h"

//タスク一覧を表示するメソッド
void Task::displayTask() const {
    std::cout << "ID: " << id 
              << " | 内容: " << title 
              << " | 状態: " << (isCompleted  ? "完了" : "未完了") 
              << " | 作成日: " << DateFormatter::format(create_date)  //formatterかける
              << " | 期限: " << DateFormatter::format(due_date)       //formatterかける
              << "\n";
}