#include <iostream>
#include <functional>
#include <vector>
#include <random>
#include <memory>

template <typename Func>
void function_processing_func(Func fun){
    std::cout << " From inside functional \n";
    std::vector<double> random_numbers;
    random_numbers = fun(10);

}

template <typename T>
std::vector<T> generate_random_numbers(const int N){
    std::vector<T> random_numbers;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::cout << " Random number seed from random device(entropy source) is : " << rd() << std::endl;
    std::normal_distribution<double> std_normal(0, 1);
    std::cout << "generate random numbers: \n " ;
    for (int i = 0; i < N ; i++){
        random_numbers.push_back(std_normal(gen));
    }
    for (auto x: random_numbers){
        std::cout << x << ",";
    }
    std::cout << std::endl;
    return random_numbers;
}

int main(){
    generate_random_numbers<double>(10);
    function_processing_func(generate_random_numbers<double>);
}
