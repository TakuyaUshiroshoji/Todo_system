#include <string>
#include <ctime>
#include <cstdio>

#include "date_formatter.h"

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
bool DateFormatter::stringToTime(const std::string &input_date, std::tm &output_date)
{
    int year, month, day;

    // 入力データのチェック
    if (sscanf(input_date.c_str(), "%d-%d-%d", &year, &month, &day) != 3)
    {
        return false;
    }

    std::tm tmp = {};
    tmp.tm_year = year - 1900;
    tmp.tm_mon = month - 1;
    tmp.tm_mday = day;

    output_date = tmp;
    return true;
}