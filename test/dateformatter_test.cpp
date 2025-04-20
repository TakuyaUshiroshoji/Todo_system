#include <gtest/gtest.h>
#include "../inc/dateformatter.h"

TEST(DateFormatterTest, FormatYMD)
{
    std::tm date = {};
    date.tm_year = 124; // 2024年
    date.tm_mon = 3;    // 4月（0始まり）
    date.tm_mday = 21;

    std::string result = DateFormatter::format(date);
    EXPECT_EQ(result, "2024-04-21");
}