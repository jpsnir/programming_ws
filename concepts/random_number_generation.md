# Random number generation
## Types
- True random number generation
- pseudo random number generation
- quasi random number generation

## Pseudo random number generators
- In c, we can generate uniform distribution of random numbers using `rand()`
    function. Then we can use inverse CDF technique to get the random numbers
    for a particular distribution
- In c++ > 11, we can use the `random` library to generate random numbers. It
   also provides various utilities to generate random numbers of different
   distributions
- Generally, the base random number generators are always uniformly distribution
    generators. [source](https://developer.nvidia.com/gpugems/gpugems3/part-vi-gpu-computing/chapter-37-efficient-random-number-generation-and-application)
    - Linear congruential generator
    - multiple recursive generator
    - Lagged Fibonacci generator
    - Mersenee twister
    - Combined Tausworthe generator
## Box muller method
- Special significance as it helps in generating pseudo random numbers for
    a normally distribution.

## Mersenne twister
