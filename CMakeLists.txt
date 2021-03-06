cmake_minimum_required(VERSION 3.22.1)

project(vector_sum_performance)

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/0e402173c97aea7a00749e825b194bfede4f2e45.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(main main.cpp)

enable_testing()

add_executable(tests tests.cpp)

target_link_libraries(
  tests
  gtest_main
)

include(GoogleTest)
gtest_discover_tests(tests)