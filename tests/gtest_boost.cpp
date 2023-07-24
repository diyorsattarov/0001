#include "gtest_boost.h"

namespace logging = boost::log;
namespace sinks = boost::log::sinks;

void setupLogging()
{
    // Create a file sink
    boost::shared_ptr<sinks::text_file_backend> fileBackend =
        boost::make_shared<sinks::text_file_backend>(
            boost::log::keywords::file_name = "log_%N.log", 
            boost::log::keywords::rotation_size = 10 * 1024 * 1024, 
            boost::log::keywords::time_based_rotation = sinks::file::rotation_at_time_point(0, 0, 0));

    // Wrap it into the frontend and register in the core.
    // The backend requires synchronization in the frontend.
    typedef sinks::synchronous_sink<sinks::text_file_backend> file_sink;
    boost::shared_ptr<file_sink> fileSink(new file_sink(fileBackend));
    logging::core::get()->add_sink(fileSink);
}

void BoostTest::SetUp() 
{
    setupLogging();
}

void BoostTest::TearDown() 
{
    boost::log::core::get()->remove_all_sinks();
}

TEST_F(BoostTest, BoostVersion) 
{
    std::string boostVersionStr = "Boost version: " + std::to_string(BOOST_VERSION / 100000) + "." +
                                   std::to_string(BOOST_VERSION / 100 % 1000) + "." +
                                   std::to_string(BOOST_VERSION % 100);
    std::cout << boostVersionStr << std::endl;

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

TEST_F(BoostTest, BoostFileLog)
{
    // Write log messages using Boost Log
    BOOST_LOG_TRIVIAL(info) << "This is an informational message logged to file.";
    BOOST_LOG_TRIVIAL(error) << "This is an error message logged to file.";
    BOOST_LOG_TRIVIAL(warning) << "This is a warning message logged to file.";

    // Flush log to ensure messages are written to the file
    boost::log::core::get()->flush();

    // Get the log messages from the sink
    std::string log_messages = sink_->getLogMessages();

    // Check if the log messages are present in the captured log
    EXPECT_NE(log_messages.find("This is an informational message logged to file."), std::string::npos);
    EXPECT_NE(log_messages.find("This is an error message logged to file."), std::string::npos);
    EXPECT_NE(log_messages.find("This is a warning message logged to file."), std::string::npos);
}