#include "foo.h"

class MockFoo : public Foo
{
public:
    MOCK_CONST_METHOD0(getFooId, int());
    MOCK_CONST_METHOD0(getFooName, std::string());
    MOCK_CONST_METHOD0(getFooValue, double());
    MOCK_METHOD1(setFooId, void(int));
    MOCK_METHOD1(setFooName, void(const std::string&));
    MOCK_METHOD1(setFooValue, void(double));
    MOCK_METHOD0(printFooInfo, void());
};

class FooTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        mockFoo = new MockFoo;
    }

    void TearDown() override
    {
        delete mockFoo;
    }

    MockFoo* mockFoo;
};

class MockBar : public Bar
{
public:
    MOCK_METHOD0(getBarValue, double());
    MOCK_METHOD1(setBarValue, void(double));
    MOCK_METHOD0(printBarInfo, void()); // Remove this line (already declared in the Bar class)

    MOCK_METHOD0(getFooId, int());
    MOCK_METHOD0(getFooName, std::string());
    MOCK_METHOD0(getFooValue, double());
    MOCK_METHOD1(setFooId, void(int));
    MOCK_METHOD1(setFooName, void(const std::string&));
    MOCK_METHOD1(setFooValue, void(double));
};

class BarTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        mockBar = new MockBar;
    }

    void TearDown() override
    {
        delete mockBar;
    }

    MockBar* mockBar;
};


TEST_F(FooTest, GetFooIdTest)
{
    EXPECT_CALL(*mockFoo, getFooId()).WillOnce(::testing::Return(42));

    int id = mockFoo->getFooId();
    ASSERT_EQ(id, 42);
}

TEST_F(FooTest, GetFooNameTest)
{
    EXPECT_CALL(*mockFoo, getFooName()).WillOnce(::testing::Return("TestFoo"));

    std::string name = mockFoo->getFooName();
    ASSERT_EQ(name, "TestFoo");
}

TEST_F(FooTest, GetFooValueTest)
{
    EXPECT_CALL(*mockFoo, getFooValue()).WillOnce(::testing::Return(3.14));

    double value = mockFoo->getFooValue();
    ASSERT_DOUBLE_EQ(value, 3.14);
}

TEST_F(FooTest, SetFooIdTest)
{
    EXPECT_CALL(*mockFoo, setFooId(100));

    mockFoo->setFooId(100);
}

TEST_F(FooTest, SetInvalidFooIdTest)
{
    Foo foo;
    int invalidId = -1;
    foo.setFooId(invalidId);
    ASSERT_EQ(foo.getFooId(), 0);
    int anotherInvalidId = 0;
    foo.setFooId(anotherInvalidId);
    ASSERT_EQ(foo.getFooId(), 0);
}

TEST_F(FooTest, SetFooNameTest)
{
    const std::string newName = "NewFoo";
    EXPECT_CALL(*mockFoo, setFooName(newName));

    mockFoo->setFooName(newName);
}

TEST_F(FooTest, SetFooValueTest)
{
    EXPECT_CALL(*mockFoo, setFooValue(10.5));

    mockFoo->setFooValue(10.5);
}

TEST_F(FooTest, PrintFooInfoTest)
{
    EXPECT_CALL(*mockFoo, printFooInfo());

    mockFoo->printFooInfo();
}


TEST_F(BarTest, GetBarValueTest)
{
    EXPECT_CALL(*mockBar, getBarValue()).WillOnce(::testing::Return(42.0));

    double value = mockBar->getBarValue();
    ASSERT_DOUBLE_EQ(value, 42.0);
}

TEST_F(BarTest, SetBarValueTest)
{
    EXPECT_CALL(*mockBar, setBarValue(3.14));

    mockBar->setBarValue(3.14);
}

TEST_F(BarTest, PrintBarInfoTest)
{
    EXPECT_CALL(*mockBar, printBarInfo());

    mockBar->printBarInfo();
}

TEST_F(BarTest, GetFooIdInheritedTest)
{
    int id = 10;
    EXPECT_CALL(*mockBar, getFooId()).WillOnce(::testing::Return(id));

    int fooId = mockBar->getFooId();
    ASSERT_EQ(fooId, id);
}

TEST_F(BarTest, GetFooNameInheritedTest)
{
    std::string name = "TestBar";
    EXPECT_CALL(*mockBar, getFooName()).WillOnce(::testing::Return(name));

    std::string fooName = mockBar->getFooName();
    ASSERT_EQ(fooName, name);
}

TEST_F(BarTest, GetFooValueInheritedTest)
{
    double value = 3.14;
    EXPECT_CALL(*mockBar, getFooValue()).WillOnce(::testing::Return(value));

    double fooValue = mockBar->getFooValue();
    ASSERT_DOUBLE_EQ(fooValue, value);
}

TEST_F(BarTest, SetFooIdInheritedTest)
{
    int id = 100;
    EXPECT_CALL(*mockBar, setFooId(id));

    mockBar->setFooId(id);
}

TEST_F(BarTest, SetFooNameInheritedTest)
{
    std::string name = "NewBar";
    EXPECT_CALL(*mockBar, setFooName(name));

    mockBar->setFooName(name);
}

TEST_F(BarTest, SetFooValueInheritedTest)
{
    double value = 5.67;
    EXPECT_CALL(*mockBar, setFooValue(value));

    mockBar->setFooValue(value);
}
