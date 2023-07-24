#ifndef GTEST_BOOST_TEST_H
#define GTEST_BOOST_TEST_H

#include <mutex>
#include <sstream>
#include <string>
#include <memory>

#include <gtest/gtest.h>

#include <boost/version.hpp>
#include <boost/chrono.hpp>
#include <boost/timer/timer.hpp>
#include <boost/log/core.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sinks/basic_sink_backend.hpp>
#include <boost/log/sinks/sync_frontend.hpp>
#include <boost/log/sources/logger.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/trivial.hpp>

class LogCaptureSink;

class BoostTest : public ::testing::Test 
{
protected:
    void SetUp() override;
    void TearDown() override;

    std::shared_ptr<LogCaptureSink> sink_; // Use std::shared_ptr
};

class LogCaptureSink : public boost::log::sinks::basic_sink_backend<
    boost::log::sinks::combine_requirements<
        boost::log::sinks::synchronized_feeding,
        boost::log::sinks::flushing
    >::type
>
{
public:
    void consume(boost::log::record_view const& rec, const std::string& message)
    {
        std::lock_guard<std::mutex> lock(mutex_);
        log_messages_ << message << "\n";
    }

    std::string getLogMessages() const
    {
        std::lock_guard<std::mutex> lock(mutex_);
        return log_messages_.str();
    }

private:
    mutable std::mutex mutex_;
    std::ostringstream log_messages_;
};
#endif 
