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

    std::string performHttpGet(const std::string& url) 
    {
        std::string response;

        CURL* curl = curl_easy_init();
        if (curl) 
        {
            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
            curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, [](char* data, size_t size, size_t nmemb, std::string* response) 
            {
                size_t totalSize = size * nmemb;
                response->append(data, totalSize);
                return totalSize;
            });
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

            CURLcode res = curl_easy_perform(curl);
            if (res != CURLE_OK) 
            {
                // Handle error if needed
                // For simplicity, we'll just set an empty response in case of an error
                response.assign("Error: Unable to perform HTTP request");
            }

            curl_easy_cleanup(curl);
        }

        return response;
    }
};

#endif // CURL_VERSION_TEST_H
