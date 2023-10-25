#include<iostream>
#include<random>
#include <typeinfo>
#include <functional>
class FunctorA{
public:
    void operator()(unsigned num){
        std::cout << "Uniform random number generator: " << num << std::endl;
    }
};

class ObjectClass{

public:
    void print(double number){
        std::cout << "Number = " << number << std::endl;
    }
};

int main(){
    std::random_device rd;
    std::mt19937 generator;
    std::normal_distribution<double> std_normal(0, 1);
    ObjectClass oc;

    FunctorA func;
    std::cout << "Datatype of rd: " << typeid(rd).name() << std::endl;
    for (int i = 0; i < 10; i++){
        oc.print(rd());
    }

    std::function<void(double)> lambda = [ &generator, &std_normal](double s){
        generator.seed(s);
        std::cout << "using lambda" << std::endl;
        for(int i = 0; i < 10; i++){
            std::cout << "Number = " << std_normal(generator) << std::endl;
        }
    };
    lambda(rd());

    std::cout << " with functor see the value of mersenee twister generator" << std::endl;
    for(int i = 0; i < 10; i++){
        func(generator());
    }


}
