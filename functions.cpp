#include <iostream>
#include <vector>
#include <chrono>
#include <numeric>
#include "sum_functions.cpp"

using namespace std;

struct ExecutionConfig
{
    int vector_length;
    int total_iterations;
    int sum_function_indicator;
};

ExecutionConfig parse_args(char **argv)
{
    const int vector_length = stoi(argv[1]);
    const int total_iterations = stoi(argv[2]);
    const int function = stoi(argv[3]);

    return ExecutionConfig{
        vector_length,
        total_iterations,
        function};
}

vector<int> init_vector(int length)
{
    vector<int> vec;
    for (int i = 0; i < length; i++)
    {
        vec.push_back(i);
    }
    return vec;
}

// define sum_function function-pointer type
typedef int (*sum_function)(const vector<int> &, int *);

sum_function init_sum_function(const int function_indicator)
{
    int (*sum_function)(const vector<int> &);
    switch (function_indicator)
    {
    case 0:
        return get_sum_of_int_vector_0;
    case 1:
        return get_sum_of_int_vector_1;
    case 2:
        return get_sum_of_int_vector_2;
    case 3:
        return get_sum_of_int_vector_3;
    case 4:
        return get_sum_of_int_vector_4;
    default:
        return get_sum_of_int_vector_0;
    }
}