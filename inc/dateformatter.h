#ifndef DATE_FORMATTER_H
#define DATE_FORMATTER_H

#include <string>
#include <ctime>

///
/// @brief DateFormatterクラスは日付変換用クラス
///
/// 日付⇔文字列を変換する
///
class DateFormatter
{
public:
    // 日付を文字列に変換するメソッド
    static std::string timeToString(const std::tm &date, const std::string &format = "%Y-%m-%d");
    // 文字列を日付構造体に変換するメソッド
    static bool stringToTime(const std::string &input_string, std::tm &output_date);
};

#endif // DATE_FORMATTER_H