import numpy as np
import sys


# Memoization can be used to improve the performance of many functions
# that have repeated and expensive computations.


def fibonacci(n, cache={}):
    '''
        Program returns nth fibonacci number in the sequence
    '''
    if n in cache:
        print(f"using cache n = {n} = {cache[n]}")
        return cache[n]
    if n == 0:
        result = 0
    elif n == 1:
        result = 1
    else:
        result = fibonacci(n-1) + fibonacci(n-2)
    cache[n] = result
    return result


print(f' f(5) = {fibonacci(5)}')
print('--------------')
print(f' f(2) = {fibonacci(2)}')
print('--------------')
print(f' f(6) = {fibonacci(6)}')
