#include <gtest/gtest.h>
#include "gtest_mytempclass.cpp"  // You can include the file containing the test suite here

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
