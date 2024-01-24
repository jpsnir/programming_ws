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
int main(int argc, char *argv[]){
    cout << " Using cuda for performing matrix and linear algebra operations" <<
        endl;
    if (argc != 2){
        cout << "usage : ./linear_algebra_eigen <N>" <<endl;
        exit(0);
    }

    // number of points
    static const int N  = std::stoi(std::string(*(argv)));
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
    std::uniform_real_distribution<float> x_dist(min, max);

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
    // c style arrays using the map class can be to used.
    // no new memory is allocated.
    Eigen::Map<Eigen::VectorXf> X(x.data(), N);
    Eigen::Map<Eigen::VectorXf> Y(y.data(), N);
    Eigen::MatrixXf A;
    A.col(0)  << X;
    A.col(1) << Eigen::VectorXf::Ones(N);
    cout << A.block(0, 0, 10, 10) << endl;
}
