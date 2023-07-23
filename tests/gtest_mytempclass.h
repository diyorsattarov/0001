#ifndef GTEST_MYTEMPLATECLASS_H
#define GTEST_MYTEMPLATECLASS_H

// Include any necessary headers for your template class here

// Example template class to test
template <typename T>
class MyTemplateClass {
public:
    MyTemplateClass() {}

    T add(T a, T b) const {
        return a + b;
    }

    // Add more functionality that you want to test

    // Add a multiplication function to test
    T multiply(T a, T b) const {
        return a * b;
    }

    // Add a division function to test (for double type only)
    T divide(T a, T b) const {
        return a / b;
    }
};

#endif // GTEST_MYTEMPLATECLASS_H
