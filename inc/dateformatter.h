#ifndef DATE_FORMATTER_H
#define DATE_FORMATTER_H

#include <string>
#include <ctime>

class DateFormatter {
public: 
    static std::string format(const std::tm& date, const std::string& format = "%Y-%m-%d");
};

#endif // DATE_FORMATTER_H