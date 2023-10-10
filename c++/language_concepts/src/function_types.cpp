#include <iostream>
#include <cstdio>
#include <functional>
#include <cmath>

/* Understanding the different implementations of
 * function, function pointer, functional,
 */

double compute_square(double x){
    return pow(x,2);
}

class Exponent{
    public:
        Exponent()=default;
        double operator ()(double x){
            return pow(x,2);
        }
        double square(double x){
            return pow(x,2);
        }
};

int main(){
    auto exp_ptr = new Exponent();
    Exponent *square_ptr = new Exponent();
    // raw c style function pointer
    // functions are stored in binary
    // with the ampersand we are storing the memory location of the instruction
    // that will be stored.
    double (*compute_square_ptr)(double) = &compute_square;
    auto func = &compute_square;
    // function pointers with classes
    double (Exponent::*compute_square_functional)(double) = &Exponent::square;
    printf("Square of 10 (raw function pointer) = %f\n", (*compute_square_ptr)(10));
    printf("Square of 10 (using auto) = %f\n", func(10));
    //using function pointers of methods with objects.
    printf("Square of 10 (method pointer) = %f\n", (exp_ptr->*compute_square_functional)(10));
    std::cout <<" Square of 10 (functor with operator overloading) " << (*square_ptr)(10) << std::endl;
    std::cout <<" Square of 10 (functor with operator overloading) " << (*exp_ptr)(10) << std::endl;

    // std function library
    std::function<double(double)> square;
    square = compute_square;

    std::function<double(Exponent&, double)> f = &Exponent::square;
    std::cout << " Square of 10 (std::function with class method): " << f(*exp_ptr, 10) << std::endl;
    std::cout << " Square of 10 (std::function) :" << square(10) << std::endl;


    // std function accepting a lambda function
    std::function<int(int)> factorial = [](int n){
        int factorial = 1;
        for (int i=1;i<=n;i++)
            factorial = factorial*i;
        return factorial;
    };

    std::cout << " The factorial of 10 (using std::function and lambda): " << factorial(10) << std::endl;
    delete exp_ptr;
    delete square_ptr;
}
