#include <gtest/gtest.h>
#include "../inc/task_manager.h"
#include "../inc/task.h"

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS(); // ← ここで登録されたすべての TEST を実行！
}

TEST(TaskManagerTest, displayTaskList)
{
    int next_id{1};
    std::string title{"test"};
    std::tm output_due_date{};
    Task new_task(next_id, title, output_due_date);

    // displayTaskList();
}