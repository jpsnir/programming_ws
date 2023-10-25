#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <cmath>
#include <string>
#include <cassert>

long factorial(int n){
        double factorial = 1;
        if (n < 0){
         std::cout<<"Positive value are required"<<std::endl;
         exit(0);
        }
        if (n==0)
            return factorial;
        for(int i=1; i<=n; i++){
            factorial = factorial*i;
        }
        return factorial;
}

float compute_total_probability(int n, int k, float p){
    float total_probability = 0;
    assert(n > k);
    auto probability_k = [](int N, int k, float p){
        long nCk = factorial(N)/(factorial(k) * factorial(N-k));
        float prb = nCk*pow(p,k)*pow(1-p, N-k);
        return prb;
    };
    for (int i=k;i <= n;i++){
            total_probability += probability_k(n, i, p);
    }
    std::cout << " Probability that greater than " << k
              << " users are using the network  from a total of " << n
              << " users : "<< total_probability << std::endl;
    return total_probability;
}

int main(int argc, char*argv[]){
    if (argc <= 1)
    {
        std::cout << " Usage: ./network_traffic_probability <N> <k> <p> \n";
        exit(0);
    }



    int N = std::atoi(argv[1]); // total users in network
    int min_k = std::atoi(argv[2]); // users
    float p = std::atof(argv[3]); // use probability


    if ( min_k > N){
        std::cerr << "k should be less than or equal to N \n";
        exit(0);
    }
    std::cout << " N = " << N << std::endl;
    std::cout << " Min k  = " << min_k << std::endl;
    std::cout << " p = " << p << std::endl;

    auto factorial_lambda = [](int n)->long{
        long factorial = 1;
        if (n < 0)
         std::domain_error("Positive value are required");
        if (n==0)
          factorial = 1;
        for(int i=1; i<=n; i++)
            factorial = factorial*i;
        return factorial;
    };

    compute_total_probability(N, min_k, p);
    std::vector<double> tp;
    int n_array[] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    for(auto n: n_array){
        tp.push_back(compute_total_probability(n, 7, p));
    }
    for(int i = 0; i < tp.size(); i++){
        std::cout << n_array[i] << "," << tp[i] << std::endl;
    }
}
