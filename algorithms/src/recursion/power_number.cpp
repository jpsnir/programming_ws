#include <cmath>
#include <iostream>
#include <cassert>

/*
 * The program computes nth power of a number using recursion.
 * It also extends the program with memoization.
 * This is written in C++
 *
 * In recursion, we need of think of the incremental operation and
 * the expression available
 * Pow(x, n) = Pow(x, n-1) * x
 * and base case is
 * Pow(x, 0) = 1
 * Pow(x, 1) = x is known
 *
 * Now think about the negative powers
 * n < 0
 * Pow(x, n) = pow(x, n+1))*x^(-1)
 * At this moment we limit to n being an integer.
 * The goal of recursion is to find the largest recursive relation
 * to exploit the time complexity.
 */

template <typename Scalar> Scalar power_recursion(Scalar x, int n) {

  if (n == 0)
    return 1;
  if (n == 1)
    return x;
  if (n == -1)
    return 1 / x;

  Scalar power;
  if (n > 0)
    power = power_recursion(x, n - 1) * x;
  else if (n < 0)
    power = power_recursion(x, n + 1) / x;
  return power;
}

/* In the previous expression, we considered the
 * recurrence relation of:
 * pow(x, n) = pow(x, n-1) * x
 * This leads to n multiplication operations.
 * However we know that when n is even
 * we can compute the power of m= x^(n/2)
 * and get pow(x, n) = m*m => pow(x, n/2)*pow(x,n/2)
 *
 * This basically reduces the number of multiplications.
 * Because we know that, if a recurrence relation has to perform
 * n/2 operation in the next call stack, total number of calls reduces to
 * log n instead of n. If n is a power of 2, then the algorithm is quite easy
 * just compute m = pow(x, n/2), and then perform pow(x, n) = m*m
 *
 * If the n is not even or power of two, then the number of steps will be
 * somewhat difficult to calcuate. But here is an attempt.
 * n = 2k + 1; pow(x, 2K + 1) = pow(x, 2k) *x    -   1
 * pow(x, 2k) = pow(x, k)*pow(x, k)              -   1
 * if k is an odd number, k = 2p + 1
 * pow(x, k) = pow(x, 2p+1) = pow(x, 2p) *x      -   1
 * pow(x, 2p) = pow(x, p) * pow(x, p)            -   1
 *
 * to get down to p recursive calls which is equivalent of n/4 calls essentially
 * Worst case there will be 2logn calls, best case there will be log n calls,
 * so the time complexity is O(logn) - for n = 2^k
 */
template <typename Scalar> Scalar power_recursion_efficient(Scalar x, int n) {

  if (n == 0)
    return 1;
  if (n == 1)
    return x;
  if (n == -1)
    return 1 / x;

  Scalar power;
  if (n > 0) {
    if (n % 2 == 0) {
      double m = power_recursion(x, n / 2);
      power = m * m;
    } else {

      power = power_recursion(x, n - 1) * x;
    }
  } else if (n < 0) {

    if (abs(n) % 2 == 0) {
      double m = power_recursion(x, n / 2);
      power = m * m;
    } else {
      power = power_recursion(x, n + 1) / x;
    }
  }
    return power;
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    std::cout << "Usage: power x n, n is an integer" << std::endl;
    exit(0);
  }
  std::string::size_type sz;
  double base = std::stod(argv[1], &sz);
  double exponent = std::stod(argv[2], &sz);
  assert(floor(exponent)==exponent);
  std::cout << " Value of the inputs are : x= " << base << " , n = " << exponent
            << "\n";
  double result = power_recursion<double>(base, exponent);
  std::cout << " Result is = " << result << std::endl;
  std::cout << " Using power function = " << pow(base, exponent) << std::endl;
  std::cout << " Using efficient recursion : "
            <<  power_recursion_efficient<double>(base, exponent)
            << "\n";
}
