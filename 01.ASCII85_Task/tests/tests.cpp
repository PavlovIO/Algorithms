/* Ilya Pavlov st129535@student.spbu.ru
	Lab-work-2
*/
#include "libraries.h"
#include<gtest/gtest.h>

std::string Testing(const std::string& s) {
    if (s == "Tests are running"){
        return "YAY";
    }
    return "NAY";
}

//Тесты
TEST(FishTest, TestsAreWorking) {
    std::string s = "Tests are running";
    EXPECT_EQ(Testing(s), "YAY");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
