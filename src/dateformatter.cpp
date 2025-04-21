#include <string>
#include <ctime>
#include <cstdio>

#include "dateformatter.h"

// 日付を文字列に変換するメソッド
std::string DateFormatter::timeToString(const std::tm &date, const std::string &format)
{
    char buffer[100];
    if (std::strftime(buffer, sizeof(buffer), format.c_str(), &date))
    {
        return std::string(buffer);
    }
    return "";
}

// 文字列を日付構造体に変換するメソッド
std::tm DateFormatter::stringToTime(const std::string &date_input)
{
    int year, month, day;
    sscanf(date_input.c_str(), "%d-%d-%d", &year, &month, &day);
    std::tm due_date{};
    due_date.tm_year = year - 1900;
    due_date.tm_mon = month - 1;
    due_date.tm_mday = day;
    return due_date;
}