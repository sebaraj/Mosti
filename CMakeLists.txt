set(CMAKE_C_COMPILER "/opt/homebrew/Cellar/llvm/20.1.3/bin/clang")
set(CMAKE_CXX_COMPILER "/opt/homebrew/Cellar/llvm/20.1.3/bin/clang++")
cmake_minimum_required(VERSION 4.0)
project(Mosti VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN On)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.16.0.zip
)

FetchContent_MakeAvailable(googletest)

enable_testing()

# add_subdirectory(tests)

# add_executable(
  # hello_test
  # tests/hello_test.cpp
# )

# link to the gtest_main target, which also sets up include directories
# target_link_libraries(
  # hello_test
  # PRIVATE
    # GTest::gtest_main
    # src
# )

include(GoogleTest)
gtest_discover_tests(hello_test)
