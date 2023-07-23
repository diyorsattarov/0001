#ifndef CURL_VERSION_TEST_H
#define CURL_VERSION_TEST_H

#include <gtest/gtest.h>
#include <curl/curl.h>

// Test fixture for libcurl version check
class CurlVersionTest : public ::testing::Test 
{
protected:
    static void SetUpTestCase() {
        // Initialize libcurl
        curl_global_init(CURL_GLOBAL_ALL);
    }

    static void TearDownTestCase() {
        // Cleanup libcurl
        curl_global_cleanup();
    }
};

#endif // CURL_VERSION_TEST_H
