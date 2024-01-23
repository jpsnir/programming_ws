#include<cstdio>
#include<cstdlib>
#include<iostream>
#include <vector>
#include<random>
#include <algorithm>
#include<eigen3/Eigen/Dense>
#include<eigen3/Eigen/Core>

using namespace std;
int main(){
    cout << " Using cuda for performing matrix and linear algebra operations" <<
        endl;

    // number of points
    const int N  = 10000;
    // line parameters
    float m = 2.0f, c = 2.0f;
    // noise parameters
    float noise_mean = 0;
    float noise_std = 0.1f;

    // x range:
    float min = -10, max = 10;

    // create data for linear regression
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<float> noise_dist(noise_mean, noise_std);
    std::uniform_int_distribution<> x_dist(min, max);

    // create data
    std::vector<float> x, y;
    x.reserve(N);
    y.reserve(N);
    for (int i = 0; i < N; i++){
        x[i] = x_dist(gen);
        y[i] = m*x[i] + c + noise_dist(gen);
    }


    // referring to the same data in heap
    // eigen vaectors can be directly initialized with
    // c style arrays or the map class can be to used.
    // no new memory is allocated. All these methods are
    // just mapping the std vector to be used with
    // eigen interface.
    Eigen::Map<Eigen::VectorXf> X3(x.data(), 100);
    cout << " first 10 values: " << X3.head(10) << std::endl;
    // new array
}
