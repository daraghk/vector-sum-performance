#include "functions.cpp"

int main(int argc, char **argv)
{
    ExecutionConfig config = parse_args(argv);
    vector<int> vec = init_vector(config.vector_length);
    int (*sum_vector_function)(const vector<int> &, int *) = init_sum_function(config.sum_function_indicator);

    // execution iterations of sum_function
    int iterations = config.total_iterations;
    double accumulated_time = 0.0;
    while (iterations > 0.0)
    {
        int x = 0;
        int *destination = &x;

        const auto start = chrono::high_resolution_clock::now();
        int sum = sum_vector_function(vec, destination);
        const auto end = chrono::high_resolution_clock::now();
        
        chrono::duration<double, milli> milliseconds = end - start;
        accumulated_time += milliseconds.count();
        --iterations;
    }

    double average_time = accumulated_time / config.total_iterations;
    cout << "TOTAL TIME: " << accumulated_time << endl;
    cout << "TOTAL ITERATIONS: " << config.total_iterations << endl;
    cout << "AVERAGE TIME: " << average_time << endl;

    return 0;
}