#include<cstdio>
#include<cstdlib>
#include<iostream>
#include <vector>
#include<random>
#include <algorithm>
#include<eigen3/Eigen/Dense>
#include<eigen3/Eigen/Core>

using namespace std;
int main(int argc, char * argv[]){

    cout << " Creating an eigen template for performing matrix and linear algebra operations" <<
        endl;
    if (argc != 4){
        cout << " Number of arguments" << argc << endl;
        cout << "usage : ./linear_algebra_eigen <N> <m> <c>" <<endl;
        exit(0);
    }

    // number of points
    //
    cout << " NUmber of integers: " << *(argv + 1) << endl;

    std::string::size_type sz;
    static const int N  = std::stoi(std::string(*(argv + 1)), &sz);
    // number of points
    // line parameters
    const float m = std::stoi(std::string(*(argv + 2)), &sz);
    const float c = std::stoi(std::string(*(argv + 3)), &sz);
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
    Eigen::VectorXf X = Eigen::Map<Eigen::VectorXf>(x.data(), N);
    Eigen::VectorXf Y = Eigen::Map<Eigen::VectorXf>(y.data(), N);
    Eigen::MatrixXf A(N, 2), b(N, 1);

    // comma initialization
    A  << X, Eigen::VectorXf::Ones(N);

    // comma initialization
    b << Y;

    // Dense matrix computations:
    Eigen::VectorXf p_estimate = A.colPivHouseholderQr().solve(b);
    Eigen::MatrixXf A1 = A;
    Eigen::ColPivHouseholderQR<Eigen::MatrixXf> dec(A);
    Eigen::VectorXf est = dec.solve(b);
    cout << " Residual from the solution: \n" << (A1*est - b).norm() << endl;
    cout << " Solution to the regression problem: \n" << p_estimate << endl;
   // p_estimate = A.partialPivLu().solve(b);
   // cout << " Solution to the regression problem (PartialPiv LU): \n"
    //    << p_estimate << endl;
    p_estimate = A.fullPivLu().solve(b) ;
    cout << " Solution to the regression problem (fullPiv LU): \n"
        << p_estimate << endl;
    p_estimate = A.householderQr().solve(b);
    cout << " Solution to the regression problem (Householder QR): \n"
         << p_estimate << endl;
    p_estimate = A.colPivHouseholderQr().solve(b);
    cout << " Solution to the regression problem (Col Piv Householder QR): \n"
         << p_estimate << endl;

    p_estimate = A.fullPivHouseholderQr().solve(b);
    cout << " Solution to the regression problem (full piv householder QR): \n"
         << p_estimate  << endl;

    p_estimate = A.completeOrthogonalDecomposition().solve(b);
    cout << " Solution to the regression problem (complete orthogonal decomposition): \n"
         << p_estimate << endl;

    // Eigen values:
    // Eigen values exist only for square matrices.
    // So use A^T.A
    Eigen::SelfAdjointEigenSolver<Eigen::MatrixXf> eigensolver(A.transpose()*A);
    if (eigensolver.info() != Eigen::Success) abort();
    cout << " Eigen values of A are : \n" << eigensolver.eigenvalues() << endl;
}
