#ifndef CURL_VERSION_TEST_H
#define CURL_VERSION_TEST_H

#include <gtest/gtest.h>
#include <curl/curl.h>
#include <string>

// Test fixture for libcurl version check
class CurlTest : public ::testing::Test 
{
protected:
    static void SetUpTestCase() 
    {
        curl_global_init(CURL_GLOBAL_ALL);
    }

    static void TearDownTestCase() 
    {
        curl_global_cleanup();
    }
};

// Function to perform an HTTP GET request using libcurl
std::string performHttpGet(const std::string& url);

#endif // CURL_VERSION_TEST_H
