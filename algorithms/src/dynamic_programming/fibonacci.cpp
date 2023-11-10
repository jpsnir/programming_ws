#include <iostream>
#include <cmath>
#include <map>

/* using memoization we can reduce the number of recursive calls
 * Originally the fib() has an upper bound recurrence relation
 * T(n) = 2T(n-1) leading to O(2^n) calls
 * By memoization, we can reduce the number of calls and reduce it
 * to O(n) calls. Memoization can bring a difference not always
 * as this drastic.
 */

std::map<int, int> memo;
int fib(int n, std::map<int, int> &memo){
    if(n <= 1)
        return n;
    if (!memo.empty() && memo.find(n) != memo.end())
        return memo[n];

    std::cout << " Function called " << std::endl;
    int a = fib(n-1, memo);
    int b = fib(n-2, memo);

        memo.insert(std::pair<int,int>(n-1, a));
        memo.insert(std::pair<int,int>(n-2, b));
    return a + b;
}

int fib_iterative(int n){
    if(n <=1)
        return n;
    int F[n];
    F[0] = 0; F[1] =1;
}
int main(){
    std::cout << " Fibonacci of f(10): " << fib(10, memo) << std::endl;
    std::cout << " --------------------------" << std::endl;
    std::cout << " Fibonacci of f(11): " << fib(11, memo) << std::endl;


}
