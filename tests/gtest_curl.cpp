#include "gtest_curl.h"

TEST_F(CurlVersionTest, CheckCurlVersion) 
{
    // Get the libcurl version
    const char* versionStr = curl_version();
    
    // Print the libcurl version
    std::cout << "libcurl version: " << versionStr << std::endl;

    // Perform the test - You can use EXPECT or ASSERT based on your needs
    EXPECT_TRUE(versionStr != nullptr);
}