#include <gtest_mytempclass.h>
#include <gtest/gtest.h>

template <typename T>
class MyTemplateClassTest : public ::testing::Test {
protected:
    MyTemplateClass<T> obj;
};

TYPED_TEST_SUITE_P(MyTemplateClassTest);

TYPED_TEST_P(MyTemplateClassTest, TestFunctionality) {
    // Test functionality of MyTemplateClass with the type 'TypeParam'
    // using 'this->obj'.
    // ...
}

REGISTER_TYPED_TEST_SUITE_P(MyTemplateClassTest, TestFunctionality);

// Specify the types you want to test with the template class.
using MyTypesToTest = ::testing::Types<int, double>;
INSTANTIATE_TYPED_TEST_SUITE_P(MyTest, MyTemplateClassTest, MyTypesToTest);
