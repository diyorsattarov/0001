#include "gtest_boost.h"

// Test case for checking the Boost version
TEST_F(BoostTest, BoostVersion) 
{
    std::string boostVersionStr = "Boost version: " + std::to_string(BOOST_VERSION / 100000) + "." +
                                   std::to_string(BOOST_VERSION / 100 % 1000) + "." +
                                   std::to_string(BOOST_VERSION % 100);

    std::cout << boostVersionStr << std::endl;

    // Add your assertions to check the Boost version, e.g., comparing with a required version
    EXPECT_TRUE(BOOST_VERSION >= 107500); // For example, check if the Boost version is at least 1.75.0
}

TEST_F(BoostTest, BoostElapsedCPUTime)
{
    std::cout << "Press Enter to stop the timer..." << std::endl;

    boost::timer::cpu_timer timer;

    // Wait for user input (Press Enter)
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Stop the timer
    timer.stop();

    // Get the elapsed CPU time
    boost::timer::cpu_times elapsedTimes = timer.elapsed();

    // Calculate the elapsed time in seconds
    double elapsedSeconds = static_cast<double>(elapsedTimes.system + elapsedTimes.user) / 1e9;
    EXPECT_GT(elapsedSeconds, 0);
    std::cout << "Elapsed time: " << elapsedSeconds << " seconds" << std::endl;
}

TEST_F(BoostTest, BoostElapsedChronoTime)
{
    std::cout << "Press Enter to stop the timer..." << std::endl;

    boost::chrono::high_resolution_clock::time_point startTime = boost::chrono::high_resolution_clock::now();

    // Wait for user input (Press Enter)
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    boost::chrono::high_resolution_clock::time_point endTime = boost::chrono::high_resolution_clock::now();

    // Calculate the elapsed time in microseconds
    boost::chrono::microseconds elapsedMicroseconds = boost::chrono::duration_cast<boost::chrono::microseconds>(endTime - startTime);
    EXPECT_GT(elapsedMicroseconds.count(), 0);
    std::cout << "Elapsed time: " << elapsedMicroseconds.count() / 1000000.0 << std::endl;
}