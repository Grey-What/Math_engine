cmake_minimum_required(VERSION 3.20)
project(MathEngine)

# Tell CMake to use C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include vcpkg toolchain
# This line is only needed if you didn't pass it on command line
# set(CMAKE_TOOLCHAIN_FILE "C:/Users/greyw/VSC_CodeCreations/Math_engine/vcpkg/scripts/buildsystems/vcpkg.cmake")

# Add your main source files
add_library(MathEngine STATIC
    src/tokenizer.cpp
)

# Include headers for your library
target_include_directories(MathEngine PUBLIC include)

# Enable testing
enable_testing()

# Find GoogleTest
find_package(GTest REQUIRED)

# Add test executable
add_executable(TokenizerTests
    tests/test_tokenizer.cpp
)

# Link GoogleTest and your library to the test executable
target_link_libraries(TokenizerTests PRIVATE MathEngine GTest::gtest GTest::gtest_main)

# Register test with CTest
add_test(NAME TokenizerTests COMMAND TokenizerTests)
