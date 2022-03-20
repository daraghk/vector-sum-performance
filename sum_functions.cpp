#include <vector>

using namespace std;

int get_sum_of_int_vector_0(const vector<int> &vec, int *destination)
{
    for (int i = 0; i < vec.size(); i++)
    {
        *destination = *destination + vec[i];
    }
    return *destination;
}

// move vec.size() out of the for loop
int get_sum_of_int_vector_1(const vector<int> &vec, int *destination)
{
    size_t vector_size = vec.size();
    for (int i = 0; i < vector_size; i++)
    {
        *destination = *destination + vec[i];
    }
    return *destination;
}

// use a local variable to accumulate the result
int get_sum_of_int_vector_2(const vector<int> &vec, int *destination)
{
    int sum = 0;
    size_t vector_size = vec.size();
    for (int i = 0; i < vector_size; i++)
    {
        sum += vec[i];
    }
    *destination = sum;
    return sum;
}

// use 2x1 loop unrolling to perform two computations per loop iteration
int get_sum_of_int_vector_3(const vector<int> &vec, int *destination)
{
    int sum = 0;
    size_t vector_size = vec.size();
    size_t first_loop_limit = vector_size - 1;

    int i;
    for (i = 0; i < first_loop_limit; i += 2)
    {
        sum = (sum + vec[i]) + vec[i + 1];
    }

    for (; i < vector_size; i++)
    {
        sum += vec[i];
    }

    *destination = sum;
    return sum;
}

// use 2x2 loop unrolling to perform two computations using two accumulators per loop iteration
int get_sum_of_int_vector_4(const vector<int> &vec, int *destination)
{
    int sum_even = 0;
    int sum_odd = 0;
    size_t vector_size = vec.size();
    size_t first_loop_limit = vector_size - 1;

    int i;
    for (i = 0; i < first_loop_limit; i += 2)
    {
        sum_even += vec[i];
        sum_odd += vec[i + 1];
    }

    int sum_of_rest = 0;
    for (; i < vector_size; i++)
    {
       sum_of_rest += vec[i];
    }

    *destination = sum_even + sum_odd + sum_of_rest;
    return *destination;
}