#ifndef DATE_FORMATTER_H
#define DATE_FORMATTER_H

#include <string>
#include <ctime>

class DateFormatter
{
public:
    // 日付を文字列に変換するメソッド
    static std::string timeToString(const std::tm &date, const std::string &format = "%Y-%m-%d");
    // 文字列を日付構造体に変換するメソッド
    static std::tm stringToTime(const std::string &input_string);
};

#endif // DATE_FORMATTER_H