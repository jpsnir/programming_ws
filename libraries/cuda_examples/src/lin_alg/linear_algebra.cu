#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cuda_runtime.h>
#include<cublas_v2.h>
#include<cusolverSp.h>
#include<cusolverDn.h>
#include<cusparse.h>
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

    float min = -10, max = 10;
    // create data for linear regression
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<float> distribution(noise_mean, noise_std);
    std::uniform_int_distribution<> x_dist(min, max);

    // create data
    std::vector<float> x, y;
    x.reserve(N);
    y.reserve(N);
    for (int i = 0; i < N; i++){
        x[i] = x_dist(gen);
        y[i] = m*x[i] + c + distribution(gen);
    }


    // referring to the same data in heap
    // eigen vaectors can be directly initialized with
    // c style arrays or the map class can be to used.
    // no new memory is allocated. All these methods are
    // just mapping the std vector to be used with
    // eigen interface.
    // no copy only pointing to the data and get the interface.
    Eigen::Map<Eigen::VectorXf> X1(x.data(), N);

    // creating a copy - one line copy to eigen matrix
    Eigen::VectorXf v2 = Eigen::Map<Eigen::VectorXf>(x.data(), N);
    Eigen::VectorXf v3 = Eigen::Map<Eigen::VectorXf, Eigen::Unaligned>(x.data(), N);

    // copy back to vector
    std::vector<float> x2(v2.data(), v2.data() + v2.cols()*v2.rows());
    //Eigen::VectorXf X2(x.data(), 100);
    for (int i = 0; i < 10; i++){
        cout << " values: "<< i << ":"
            << " original = " << x[i]
            << ", mapped  = " << X1[i]
            << ", copied to eigen =" << v2[i]
            << ", copied to eigen - unaligned =" << v3[i]
            << ", copied back to vector =" << x2[i]
            << std::endl;
    }
}
