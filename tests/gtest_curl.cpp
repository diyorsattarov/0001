#include "gtest_curl.h"

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
    std::string url = "https://example.com";

    // Perform the HTTP GET request
    std::string response = performHttpGet(url);

    // Output the entire response for debugging
    std::cout << "HTTP Response: " << response << std::endl;

    // Check if the response is not empty to ensure the request was successful
    EXPECT_FALSE(response.empty());

    std::string expectedResponse = "Expected response from example.com";
    EXPECT_EQ(response, expectedResponse);
}
