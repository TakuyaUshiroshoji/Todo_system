#include <gtest/gtest.h>
#include "../inc/date_formatter.h"

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

/// @brief 入力データが問題なく、日付変換成功するテスト
/// @param input_date 入力データ
/// @param output_date 日付変換後の日付構造体
TEST(DateFormatterTest, stringToTime1)
{
    std::string input_date{"2024-04-21"};
    std::tm output_date{};
    bool result{DateFormatter::stringToTime(input_date, output_date)};
    EXPECT_TRUE(result);
    EXPECT_EQ(output_date.tm_year, 124);
    EXPECT_EQ(output_date.tm_mon, 3);
    EXPECT_EQ(output_date.tm_mday, 21);
}

/// @brief 入力データが不正でfalseが返ってくるテスト
/// @param input_date 入力データ
/// @param output_date 日付変換後の日付構造体
TEST(DateFormatterTest, stringToTime2)
{
    std::string input_date{"2024-04"};
    std::tm output_date{};
    bool result{DateFormatter::stringToTime(input_date, output_date)};
    EXPECT_FALSE(result);
}