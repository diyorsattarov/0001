#include <gtest/gtest.h>
#include "gtest_mytempclass.h"

// Test fixture for MyTemplateClass
template <typename T>
class MyTemplateClassTest : public ::testing::Test {
protected:
    MyTemplateClass<T> obj;
};

// Specify the types you want to test with the template class.
using MyTypesToTest = ::testing::Types<int, double>;
TYPED_TEST_SUITE_P(MyTemplateClassTest);

TYPED_TEST_P(MyTemplateClassTest, TestFunctionality) {
    // Test functionality of MyTemplateClass with the type 'TypeParam'
    // using 'this->obj'.
    // Add your tests here
    ASSERT_EQ(this->obj.add(2, 3), 5);
    ASSERT_EQ(this->obj.add(4.5, 2.5), 7.0);
}

REGISTER_TYPED_TEST_SUITE_P(MyTemplateClassTest, TestFunctionality);

INSTANTIATE_TYPED_TEST_SUITE_P(MyTest, MyTemplateClassTest, MyTypesToTest);


TEST(PauseTest, Pause) {
    std::system("pause");
    SUCCEED();
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
