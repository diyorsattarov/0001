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
git clone https://github.com/your-username/collectione.git
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
│   ├─ collection1.h
│   ├─ collection2.h
│   └─ ...
├─ tests/        # Unit tests using Google Test framework
│   ├─ gtest_main.cpp
│   ├─ test_collection1.cpp
│   ├─ test_collection2.cpp
│   └─ ...
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
[==========] Running 4 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 4 tests from BoostTest
[ RUN      ] BoostTest.BoostVersion
Boost version: 1.82.0
[       OK ] BoostTest.BoostVersion (0 ms)
[ RUN      ] BoostTest.BoostElapsedCPUTime
Press Enter to stop the timer...

C:/msys64/home/root/collectione/tests/gtest_boost.cpp:43: Failure
Expected: (elapsedSeconds) > (0), actual: 0 vs 0

Elapsed time: 0 seconds
[  FAILED  ] BoostTest.BoostElapsedCPUTime (3538 ms)
[ RUN      ] BoostTest.BoostElapsedChronoTime
Press Enter to stop the timer...

Elapsed time: 3.68208
[       OK ] BoostTest.BoostElapsedChronoTime (3683 ms)
[ RUN      ] BoostTest.BoostLogTrivial
[2023-07-23 22:27:06.230615] [0x00003228] [trace]   A trace severity message
[2023-07-23 22:27:06.244860] [0x00003228] [debug]   A debug severity message
[2023-07-23 22:27:06.258689] [0x00003228] [info]    An informational severity message
[2023-07-23 22:27:06.274936] [0x00003228] [warning] A warning severity message
[2023-07-23 22:27:06.288952] [0x00003228] [error]   An error severity message
[2023-07-23 22:27:06.302081] [0x00003228] [fatal]   A fatal severity message
Assertion failed: px != 0, file C:/msys64/mingw64/include/boost/smart_ptr/shared_ptr.hpp, line 784
```

## Contributing

Contributions to the Collectione project are welcome! If you find a bug, have a suggestion, or want to add new features, please create an issue or submit a pull request.

## License

The Collectione project is licensed under the [MIT License](LICENSE). Feel free to use, modify, and distribute the code as per the terms of the license.