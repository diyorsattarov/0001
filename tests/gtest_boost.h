#ifndef GTEST_BOOST_H
#define GTEST_BOOST_H

#include <gtest/gtest.h>
#include <boost/version.hpp>
#include <string>

// Test fixture for libcurl version check
class BoostTest : public ::testing::Test 
{
protected:
    static void SetUpTestCase() 
    {
        
    }

    static void TearDownTestCase() 
    {
        
    }

};

#endif // GTEST_BOOST_H
