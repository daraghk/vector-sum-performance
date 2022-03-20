#include <gtest/gtest.h>
#include "functions.cpp"

TEST(VectorSumTests, CorrectnessFunction0)
{
    vector<int> vec = init_vector(10000);
    int expected_result = accumulate(vec.begin(), vec.end(), 0);
    int x = 0;
    int *destination = &x;
    int result = get_sum_of_int_vector_0(vec, destination);
    EXPECT_EQ(expected_result, result);
}

TEST(VectorSumTests, CorrectnessFunction1)
{
    vector<int> vec = init_vector(10000);
    int expected_result = accumulate(vec.begin(), vec.end(), 0);
    int x = 0;
    int *destination = &x;
    int result = get_sum_of_int_vector_1(vec, destination);
    EXPECT_EQ(expected_result, result);
}

TEST(VectorSumTests, CorrectnessFunction2)
{
    vector<int> vec = init_vector(10000);
    int expected_result = accumulate(vec.begin(), vec.end(), 0);
    int x = 0;
    int *destination = &x;
    int result = get_sum_of_int_vector_2(vec, destination);
    EXPECT_EQ(expected_result, result);
}

// sum function 3 uses 2x1 loop unrolling
TEST(VectorSumTests, CorrectnessFunction3)
{
    vector<int> vec = init_vector(10000);
    int expected_result = accumulate(vec.begin(), vec.end(), 0);
    int x = 0;
    int *destination = &x;
    int result = get_sum_of_int_vector_3(vec, destination);
    EXPECT_EQ(expected_result, result);
}

// sum function 4 uses 2x2 loop unrolling
TEST(VectorSumTests, CorrectnessFunction4)
{
    vector<int> vec = init_vector(10000);
    int expected_result = accumulate(vec.begin(), vec.end(), 0);
    int x = 0;
    int *destination = &x;
    int result = get_sum_of_int_vector_4(vec, destination);
    EXPECT_EQ(expected_result, result);
}

// sum function 3 uses 2x1 loop unrolling
TEST(VectorSumTests, CorrectnessFunction3OddNumberOfElements)
{
    vector<int> vec = init_vector(1243214);
    int expected_result = accumulate(vec.begin(), vec.end(), 0);
    int x = 0;
    int *destination = &x;
    int result = get_sum_of_int_vector_3(vec, destination);
    EXPECT_EQ(expected_result, result);
}

// sum function 4 uses 2x2 loop unrolling
TEST(VectorSumTests, CorrectnessFunction4OddNumberOfElements)
{
    vector<int> vec = init_vector(12432145);
    int expected_result = accumulate(vec.begin(), vec.end(), 0);
    int x = 0;
    int *destination = &x;
    int result = get_sum_of_int_vector_4(vec, destination);
    EXPECT_EQ(expected_result, result);
}