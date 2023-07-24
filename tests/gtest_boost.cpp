#include "gtest_boost.h"

// Test case for checking the Boost version
TEST_F(BoostTest, CheckBoostVersion) 
{
    std::string boostVersionStr = "Boost version: " + std::to_string(BOOST_VERSION / 100000) + "." +
                                   std::to_string(BOOST_VERSION / 100 % 1000) + "." +
                                   std::to_string(BOOST_VERSION % 100);

    std::cout << boostVersionStr << std::endl;

    // Add your assertions to check the Boost version, e.g., comparing with a required version
    EXPECT_TRUE(BOOST_VERSION >= 107500); // For example, check if the Boost version is at least 1.75.0
}