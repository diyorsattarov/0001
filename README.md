# Collectione

Collectione is a C++ project that provides various collection classes and utilities. It aims to make working with C++ easier and more efficient.

## TODO
    - LinkedListTest comprehensive test suite 
    - Queue/Stack/Heap test suite
    - Boost.Log

## Table of Contents

- [Introduction](#introduction)
- [Getting Started](#getting-started)
- [Directory Structure](#directory-structure)
- [Building the Project](#building-the-project)
- [Running Tests](#running-tests)
- [Contributing](#contributing)
- [License](#license)

## Introduction

The Collectione project consists of two main components: `src` and `tests`. The `src` directory contains the implementation of various collection classes and utilities, while the `tests` directory contains unit tests for these classes using Google Test framework.

## Getting Started

To get started with the Collectione project, follow these steps:

1. Clone the repository:

```bash
git clone https://github.com/diyooor/collectione.git
```

2. Make sure you have CMake and a C++ compiler installed on your system.

3. Build the project using CMake:

```bash
cd collectione
cmake .
cmake --build .
```

## Directory Structure

The directory structure of the project is as follows:

```
collectione/
├─ extern/       # External libraries (e.g., Google Test)
├─ src/          # Implementation of collection classes and utilities
│   ├─ main.cpp
│   ├─ CMakeLists.txt
│   └─ ...
├─ tests/        # Unit tests using Google Test framework
│   ├─ gtest_main.cpp *
|   ├─ gmock_performance.cpp
|   ├─ gmock_foo.cpp
│   ├─ gmock_linkedlist.cpp 
│   ├─ gmock_node.cpp
|   ├─ linkedlist.h
|   ├─ node.h
│   └─ CMakeLists.txt
├─ CMakeLists.txt
├─ README.md
└─ ...
```

## Building the Project

To build the Collectione project, follow these steps:

```bash
cd collectione
cmake .
cmake --build .
```

The built executables will be located in the `build/bin` directory.

## Running Tests

The Collectione project uses Google Test for unit testing. To run the tests, execute the following command after building the project:

```bash
cd bin
.\tests.exe
```

```sample tests output
λ .\bin\tests.exe
[==========] Running 19 tests from 4 test suites.
[----------] Global test environment set-up.
[----------] 8 tests from FooTest
[ RUN      ] FooTest.GetFooIdTest
[       OK ] FooTest.GetFooIdTest (0 ms)
[ RUN      ] FooTest.GetFooNameTest
[       OK ] FooTest.GetFooNameTest (0 ms)
[ RUN      ] FooTest.GetFooValueTest
[       OK ] FooTest.GetFooValueTest (0 ms)
[ RUN      ] FooTest.SetFooIdTest
[       OK ] FooTest.SetFooIdTest (0 ms)
[ RUN      ] FooTest.SetInvalidFooIdTest
[       OK ] FooTest.SetInvalidFooIdTest (0 ms)
[ RUN      ] FooTest.SetFooNameTest
[       OK ] FooTest.SetFooNameTest (0 ms)
[ RUN      ] FooTest.SetFooValueTest
[       OK ] FooTest.SetFooValueTest (0 ms)
[ RUN      ] FooTest.PrintFooInfoTest
[       OK ] FooTest.PrintFooInfoTest (0 ms)
[----------] 8 tests from FooTest (125 ms total)

[----------] 9 tests from BarTest
[ RUN      ] BarTest.GetBarValueTest
[       OK ] BarTest.GetBarValueTest (0 ms)
[ RUN      ] BarTest.SetBarValueTest
[       OK ] BarTest.SetBarValueTest (0 ms)
[ RUN      ] BarTest.PrintBarInfoTest
[       OK ] BarTest.PrintBarInfoTest (0 ms)
[ RUN      ] BarTest.GetFooIdInheritedTest
[       OK ] BarTest.GetFooIdInheritedTest (0 ms)
[ RUN      ] BarTest.GetFooNameInheritedTest
[       OK ] BarTest.GetFooNameInheritedTest (0 ms)
[ RUN      ] BarTest.GetFooValueInheritedTest
[       OK ] BarTest.GetFooValueInheritedTest (0 ms)
[ RUN      ] BarTest.SetFooIdInheritedTest
[       OK ] BarTest.SetFooIdInheritedTest (0 ms)
[ RUN      ] BarTest.SetFooNameInheritedTest
[       OK ] BarTest.SetFooNameInheritedTest (0 ms)
[ RUN      ] BarTest.SetFooValueInheritedTest
[       OK ] BarTest.SetFooValueInheritedTest (0 ms)
[----------] 9 tests from BarTest (158 ms total)

[----------] 1 test from FooPerformanceTest
[ RUN      ] FooPerformanceTest.MeasureGetFooValueTime
Average execution time for getFooValue(): 2 nanoseconds
[       OK ] FooPerformanceTest.MeasureGetFooValueTime (3 ms)
[----------] 1 test from FooPerformanceTest (27 ms total)

[----------] 1 test from BarPerformanceTest
[ RUN      ] BarPerformanceTest.MeasureGetBarValueTime
Average execution time for getFooValue(): 2 nanoseconds
[       OK ] BarPerformanceTest.MeasureGetBarValueTime (3 ms)
[----------] 1 test from BarPerformanceTest (24 ms total)

[----------] Global test environment tear-down
[==========] 19 tests from 4 test suites ran. (435 ms total)
[  PASSED  ] 19 tests.
```

## Contributing

Contributions to the Collectione project are welcome! If you find a bug, have a suggestion, or want to add new features, please create an issue or submit a pull request.

## License

The Collectione project is licensed under the [MIT License](LICENSE). Feel free to use, modify, and distribute the code as per the terms of the license.