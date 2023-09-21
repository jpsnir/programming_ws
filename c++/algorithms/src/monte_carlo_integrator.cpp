#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>

/*
 * Expected value of a function
 * E(g(x)) = integral( g(x)*f(x)), f(x) being the probability density.
 * E(g(x)) ~ = 1/n sum(g(x_i))
 *
 * Using law of large numbers to find a converged expected value.
 */

double integrand(double x);
double monteCarloEstimate(double lowBound, double upBound, int interations);
double monteCarloEstimateSTD(double lowBound, double upBound, int iterations);
int main(int argc, char* argv[]){
    if (argc != 4){
        std::cout << " Usage : monte_carlo_integrator <lower limit> <upper limit> <iterations> \n";
        exit(1);
    }

    double lower_b, upper_b;
    int iterations;
    std::string::size_type sz;
    for (int i = 0; i < 4; i++)
        std::cout << " input " << i << ":" << *(argv + i) << std::endl;
    lower_b = std::stod(*(argv + 1), &sz);
    upper_b = std::stod(*(argv + 2), &sz);
    iterations = std::stoi(*(argv + 3), &sz);

    double estimate = monteCarloEstimate(lower_b, upper_b, iterations);
    printf("Estimate for %.1f -> %.1f is %.2f, (%i iterations)\n", lower_b,
            upper_b, estimate, iterations);

    // analysis with changing number of iterations
    for (int i =1; i<6; i++){
        iterations = 2*pow(4, i);
        double std_dev  = monteCarloEstimateSTD(lower_b, upper_b, iterations);

    }
}

double integrand(double x){
    return pow(x,4)*exp(-x);
}

double monteCarloEstimate(double low_b, double up_b, int iterations)
{
    double t_sum = 0;
    double rand_num, f_val;
    int iter = 0;
    std::cout << " max random number: " << RAND_MAX << "\n";
    while(iter < iterations - 1){
        // generate a random number between low_b and up_b
        rand_num = low_b + (float(rand())/RAND_MAX)*(up_b - low_b);
        // get the value of function at that point.
        f_val = integrand(rand_num);

        t_sum += f_val;
        iter++;
    }

    double estimate = (up_b - low_b)*t_sum/iterations;
    return estimate;

}

double monteCarloEstimateSTD(double low_b, double up_b, int iterations){
    double t_sum = 0;
    double t_sum_squared = 0;
    int iter = 0;
    while(iter < iterations - 1){
        double rand_num = low_b + (float(rand())/RAND_MAX)*(up_b - low_b);
        double f_val = integrand(rand_num);
        t_sum += f_val;
        t_sum_squared += pow(f_val, 2);
        iter ++;
    }
    //std::cout << " iterations = " << iter << " : total = " << iterations << std::endl;
    double estimate = (up_b - low_b)*t_sum/iter;
    double exp = t_sum / iter;
    double exp_sq = t_sum_squared/ iter;
    // TODO : why for 8 samples the variance is low,
    // is there a bug. not able to figure it out.
    printf(" exp: %f, exp_sq: %f,   Difference: %f \n", exp, exp_sq, exp_sq - pow(exp,2));
    double std_dev = (up_b - low_b)*pow((exp_sq - pow(exp,2))/iter, 0.5);
    printf("Estimate: %.4f, std_dev for %.1f -> %.1f is %f, (%i iterations)\n", estimate, low_b,
            up_b, std_dev, iterations);
    return std_dev;
}
