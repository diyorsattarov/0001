# Collectione

Collectione is a C++ project that provides various collection classes and utilities. It aims to make working with C++ easier and more efficient.

## TODO
    Boost.Log

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
    ├─ gtest_llist.cpp *
│   ├─ gtest_boost.cpp 
│   ├─ gtest_boost.h 
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
[==========] Running 14 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 14 tests from LinkedListTest
[ RUN      ] LinkedListTest.InsertTest
[       OK ] LinkedListTest.InsertTest (0 ms)
[ RUN      ] LinkedListTest.DisplayTest
[       OK ] LinkedListTest.DisplayTest (2 ms)
[ RUN      ] LinkedListTest.MemoryManagementTest
[       OK ] LinkedListTest.MemoryManagementTest (0 ms)
[ RUN      ] LinkedListTest.DefaultConstruction
[       OK ] LinkedListTest.DefaultConstruction (0 ms)
[ RUN      ] LinkedListTest.InsertAndRemoveTest
[       OK ] LinkedListTest.InsertAndRemoveTest (0 ms)
[ RUN      ] LinkedListTest.InsertAndRemoveFromEmptyList
[       OK ] LinkedListTest.InsertAndRemoveFromEmptyList (0 ms)
[ RUN      ] LinkedListTest.LargeListTest
[       OK ] LinkedListTest.LargeListTest (15 ms)
[ RUN      ] LinkedListTest.RemoveLastElementTest
[       OK ] LinkedListTest.RemoveLastElementTest (0 ms)
[ RUN      ] LinkedListTest.SizeTest
[       OK ] LinkedListTest.SizeTest (0 ms)
[ RUN      ] LinkedListTest.InsertAndDisplayNegativeNumbers
[       OK ] LinkedListTest.InsertAndDisplayNegativeNumbers (2 ms)
[ RUN      ] LinkedListTest.InsertAndRemoveRandomTest
[       OK ] LinkedListTest.InsertAndRemoveRandomTest (10 ms)
[ RUN      ] LinkedListTest.InsertAndRemoveSameValueTest
[       OK ] LinkedListTest.InsertAndRemoveSameValueTest (10 ms)
[ RUN      ] LinkedListTest.EmptySizeTest
[       OK ] LinkedListTest.EmptySizeTest (0 ms)
[ RUN      ] LinkedListTest.LargeInsertAndRemoveTest
[       OK ] LinkedListTest.LargeInsertAndRemoveTest (0 ms)
[----------] 14 tests from LinkedListTest (89 ms total)

[----------] Global test environment tear-down
[==========] 14 tests from 1 test suite ran. (122 ms total)
[  PASSED  ] 14 tests.
```

## Contributing

Contributions to the Collectione project are welcome! If you find a bug, have a suggestion, or want to add new features, please create an issue or submit a pull request.

## License

The Collectione project is licensed under the [MIT License](LICENSE). Feel free to use, modify, and distribute the code as per the terms of the license.