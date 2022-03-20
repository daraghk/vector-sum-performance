# vector-sum-performance

**Sum function purpose**: to sum up the elements in a vector and store the result in some destination.  
**Sum function investigation**: to observe the effects of changes made to the 'sum function' implementation, using _un-optimized compiled code_.  
  
Sum function types:  
0 -> Basic implementation.  
1 -> Remove vector length calculation from loop.  
2 -> Accumulate result in a local variable.  
3 -> Use 2x1 loop unrolling to perform 2 computations per loop iteration.  
4 -> Use 2x2 loop unrolling with 2 accumulator variables to achieve two-way instruction level parallelism.  
