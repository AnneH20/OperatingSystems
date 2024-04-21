cmake_minimum_required(VERSION 3.0)
project(ProcessExampleTests)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set the path to Google Test
set(GTEST_ROOT "/path/to/googletest")

# Find Google Test package
find_package(GTest REQUIRED)

# Include Google Test headers
include_directories(${GTEST_INCLUDE_DIRS})

# Add the test executable target
add_executable(ProcessExampleTests tests.cpp)

# Link the test executable with Google Test
target_link_libraries(ProcessExampleTests ${GTEST_BOTH_LIBRARIES} pthread)

