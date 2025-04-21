#include <gtest/gtest.h>
#include "../inc/dateformatter.h"

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS(); // ← ここで登録されたすべての TEST を実行！
}

TEST(DateFormatterTest, timeToString)
{
    std::tm date = {};
    date.tm_year = 124; // 2024年
    date.tm_mon = 3;    // 4月（0始まり）
    date.tm_mday = 21;

    std::string result = DateFormatter::timeToString(date);
    EXPECT_EQ(result, "2024-04-21");
}
TEST(DateFormatterTest, stringToTime)
{
    std::string date_input{"2024-04-21"};
    std::tm result{DateFormatter::stringToTime(date_input)};
    EXPECT_EQ(result.tm_year, 124);
    EXPECT_EQ(result.tm_mon, 3);
    EXPECT_EQ(result.tm_mday, 21);
}