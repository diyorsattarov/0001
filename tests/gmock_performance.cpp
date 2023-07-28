#include "foo.h"

constexpr int PERFORMANCE_TEST_ITERATIONS = 1000000;

class FooPerformanceTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
    }

    void TearDown() override
    {
    }
};

TEST_F(FooPerformanceTest, MeasureGetFooValueTime)
{
    Foo foo;
    auto startTime = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < PERFORMANCE_TEST_ITERATIONS; ++i)
    {
        foo.getFooValue();
    }
    auto endTime = std::chrono::high_resolution_clock::now();
    auto elapsedTime = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime).count() / PERFORMANCE_TEST_ITERATIONS;
    std::cout << "Average execution time for getFooValue(): " << elapsedTime << " nanoseconds" << std::endl;
}

class BarPerformanceTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
    }

    void TearDown() override
    {
    }
};

TEST_F(BarPerformanceTest, MeasureGetBarValueTime)
{
    Bar bar(1, "TestBar", 0.0, 42.0);
    auto startTime = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < PERFORMANCE_TEST_ITERATIONS; ++i)
    {
        bar.getFooValue();
    }
    auto endTime = std::chrono::high_resolution_clock::now();
    auto elapsedTime = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime).count() / PERFORMANCE_TEST_ITERATIONS;
    std::cout << "Average execution time for getFooValue(): " << elapsedTime << " nanoseconds" << std::endl;
}