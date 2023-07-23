#include "gtest_mytempclass.h"  
#include <gtest/gtest.h>

template <typename T>
class MyTemplateClassTest : public ::testing::Test {
protected:
    MyTemplateClass<T> obj;
};

TYPED_TEST_SUITE_P(MyTemplateClassTest);

// Test addition functionality
TYPED_TEST_P(MyTemplateClassTest, TestAddition) {
    ASSERT_EQ(this->obj.add(2, 3), 5);
    ASSERT_EQ(this->obj.add(4, -2), 2);
    ASSERT_EQ(this->obj.add(-5, -5), -10);
}

// Test multiplication functionality
TYPED_TEST_P(MyTemplateClassTest, TestMultiplication) {
    ASSERT_EQ(this->obj.multiply(2, 3), 6);
    ASSERT_EQ(this->obj.multiply(4, -2), -8);
    ASSERT_EQ(this->obj.multiply(-5, -5), 25);
}

// Test division functionality (for double type only)
TYPED_TEST_P(MyTemplateClassTest, TestDivision) {
    if constexpr (std::is_same_v<TypeParam, double>) {
        ASSERT_DOUBLE_EQ(this->obj.divide(10.0, 2.0), 5.0);
        ASSERT_DOUBLE_EQ(this->obj.divide(4.0, 0.5), 8.0);
    }
}

REGISTER_TYPED_TEST_SUITE_P(MyTemplateClassTest, TestAddition, TestMultiplication, TestDivision);

// Manual instantiation for each type in MyTypesToTest
using MyTypesToTest = ::testing::Types<int, double>;
INSTANTIATE_TYPED_TEST_SUITE_P(MyTestInt, MyTemplateClassTest, ::testing::Types<int>);
INSTANTIATE_TYPED_TEST_SUITE_P(MyTestDouble, MyTemplateClassTest, ::testing::Types<double>);
