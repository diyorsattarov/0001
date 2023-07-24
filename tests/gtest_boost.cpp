#include "gtest_boost.h"

namespace logging = boost::log;
namespace sinks = boost::log::sinks;

void BoostTest::SetUp() {}

void BoostTest::TearDown() 
{
boost::log::core::get()->remove_all_sinks();
}

TEST_F(BoostTest, BoostVersion) 
{
std::string boostVersionStr =  "Boost version: "  + 
std::to_string(BOOST_VERSION / 100000)      + "." +
std::to_string(BOOST_VERSION / 100 % 1000)  + "." +
std::to_string(BOOST_VERSION % 100);
std::cout << boostVersionStr << 
std::endl;
EXPECT_TRUE(BOOST_VERSION >= 107500); 
}

TEST_F(BoostTest, BoostElapsedChronoTime)
{
std::cout << "Press Enter to stop the timer..." << std::endl;
boost::chrono::high_resolution_clock::time_point startTime = boost::chrono::high_resolution_clock::now();
std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
boost::chrono::high_resolution_clock::time_point endTime = boost::chrono::high_resolution_clock::now();
boost::chrono::microseconds elapsedMicroseconds = boost::chrono::duration_cast<boost::chrono::microseconds>(endTime - startTime);
EXPECT_GT(elapsedMicroseconds.count(), 0);
std::cout << "Elapsed time: " << elapsedMicroseconds.count() / 1000000.0 << std::endl;
}

TEST_F(BoostTest, BoostLogTrivial)
{
BOOST_LOG_TRIVIAL(trace) << "A trace severity message";
BOOST_LOG_TRIVIAL(debug) << "A debug severity message";
BOOST_LOG_TRIVIAL(info) << "An informational severity message";
BOOST_LOG_TRIVIAL(warning) << "A warning severity message";
BOOST_LOG_TRIVIAL(error) << "An error severity message";
BOOST_LOG_TRIVIAL(fatal) << "A fatal severity message";

std::string log_messages = sink_->getLogMessages();

EXPECT_NE(log_messages.find("A trace severity message"), std::string::npos);
EXPECT_NE(log_messages.find("A debug severity message"), std::string::npos);
EXPECT_NE(log_messages.find("An informational severity message"), std::string::npos);
EXPECT_NE(log_messages.find("A warning severity message"), std::string::npos);
EXPECT_NE(log_messages.find("An error severity message"), std::string::npos);
EXPECT_NE(log_messages.find("A fatal severity message"), std::string::npos);
}