#include "gtest_curl.h"

std::string performHttpGet(const std::string& url) 
{
    std::string response;

    CURL* curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, [](char* data, size_t size, size_t nmemb, std::string* response) {
            size_t totalSize = size * nmemb;
            response->append(data, totalSize);
            return totalSize;
        });
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        CURLcode res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            // Handle error if needed
            // For simplicity, we'll just set an empty response in case of an error
            response = "";
        }

        curl_easy_cleanup(curl);
    }

    return response;
}


TEST_F(CurlTest, CheckCurlVersion) 
{
    const char* versionStr = curl_version();
    
    std::cout << "libcurl version: " << versionStr << std::endl;

    EXPECT_TRUE(versionStr != nullptr);
}


// Test case for HTTP GET request
TEST_F(CurlTest, HttpGetRequest) 
{
    // Replace this URL with the URL you want to test
    std::string url = "https://www.example.com";

    // Perform the HTTP GET request
    std::string response = performHttpGet(url);

    // Output the response for debugging (optional)
    std::cout << "HTTP Response: " << response << std::endl;

    // Add your assertions to check the response
    // For example, you can check if the response contains specific data or if the status code is as expected
    EXPECT_FALSE(response.empty());
}