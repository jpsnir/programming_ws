#include <iostream>
#include <cmath>
/*
 * Program to compare the timing difference between recursion and looping
 * The program is simply doing recursive sum.
 * Sum(n) = sum(n-1) + n^2
 * Sum(0) = 0
 *
 * can be programmed with recursion or a simple for loop
 *
 * Recursion can be thought of as an atomic operation at nth step.
 * It is reverse of a loop. 
 * Loop can be thought to iteratively for an operation that has to be done
 * multiple times.
 * If the same operation updates a particular state,
 * recursion is a good way to implement the code.
 */

long sum_with_loop(int n){
    long sum = 0;
    for (int i=0; i<= n; i++){
        sum = sum + pow(i, 2);
    }
    return sum;
}

// c style recursion with pointers
long sum_with_recursion( int n){
    if(n==0)
     return 0;
    long sum = sum_with_recursion(n - 1) + pow(n,2);
    return sum;
}

int main(){
    int n = 10;
    int sum = n*(n+1)*(2*n+1)/6;

    std::cout << " Sum with formula : " << sum << "\n";
    std::cout << " Sum with recursion: " << sum_with_recursion(n) << "\n";
    std::cout << " Sum with loop: " << sum_with_loop(n) << "\n";

}
