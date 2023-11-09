#include<iostream>
#include<cmath>

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
 *
 */
template<typename Scalar>
Scalar power_recursion(Scalar x, int n){

    if(n==0)
        return 1;
    if(n==1)
        return x;
    if(n==-1)
        return 1/x;

    Scalar power;
    if (n > 0)
      power = power_recursion(x, n-1)*x;
    else if (n < 0)
      power = power_recursion(x,n+1)/x;
    return power;
}

int main(int argc, char* argv[]){
    if (argc != 3){
        std::cout << "Usage: power x n, n is an integer" << std::endl;
        exit(0);
    }
    std::string::size_type sz;
    double base = std::stod(argv[1], &sz);
    double exponent = std::stod(argv[2], &sz);
    std::cout << " Value of the inputs are : x= "
              << base << " , n = " << exponent << "\n";
    double result= power_recursion<double>(base, exponent);
    std::cout << " Result is = " << result << std::endl;
    std::cout << " Using power function = " << pow(base, exponent) << std::endl;
}
