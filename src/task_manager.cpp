#include <string>
#include <ctime>
#include <iostream>

#include "task_manager.h"
#include "dateformatter.h"

int TaskManager::addTask()
{
    std::cout << "タイトルを入力してください: ";
    std::getline(std::cin, title);
    std::cout << "期限を YYYY-MM-DD 形式で入力してください: ";
    std::getline(std::cin, due_date);

    // 入力された日付文字列を日付構造体に変換
    DateFormatter::stringToTime(due_date);
}