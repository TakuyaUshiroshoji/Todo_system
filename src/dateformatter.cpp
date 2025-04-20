#include "dateformatter.h"
#include <string>
#include <ctime>

// 日付を文字列に変換するメソッド
std::string format(const std::tm& date, const std::string& format = "%Y-%m-%d") {
    char buffer[100];
    if(std::strftime(buffer, sizeof(buffer), format.c_str(), &date)) {
        return std::string(buffer);
    };
    return "";
}