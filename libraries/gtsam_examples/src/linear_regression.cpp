#include<iostream>
#include<gtsam/3rdparty/Eigen/Eigen/Dense>
#include<gtsam/linear/GaussianFactorGraph.h>
#include<gtsam/inference/Key.h>
#include<gtsam/base/Matrix.h>
#include<gtsam/linear/Sampler.h>
#include<gtsam/linear/NoiseModel.h>
#include<gtsam/linear/JacobianFactor.h>
#include<gtsam/linear/VectorValues.h>
#include<gtsam/linear/ConjugateGradientSolver.h>
#include <gtsam/inference/Symbol.h>

using namespace gtsam;

int main(){
    int N = 100;
    Eigen::VectorXd x, y, e;
    Eigen::Matrix<double, 100, 1> sigmas =  Eigen::Matrix<double, 100 ,1>::Ones();
    Vector1 sigma = 0.5*Vector1::Ones(1);
    SharedDiagonal nModel = noiseModel::Diagonal::Sigmas(sigmas);
    Sampler sampler(nModel);
    e = sampler.sample();
    x = Eigen::VectorXd::LinSpaced(N, 1, 10);
    double a = 1.5, b = 1;
    Vector2 parameters;
    // In a linear regression problem, the variables to be estimated are
    // a and b. So as per the general residual relation e = Ax - b
    // The matrix is the Jacobian, x is the variable to be solved for and b is
    // the value
    // In linear regression (1D) we have x = [a, b] as our variable.
    // p(a,b/x_i,y_i)  = e^-(y_i-J_i*x)^2, J_i depends on the measurements and
    // b_i (or y_i) also depends on the measurements.
    y = a*x + b*Eigen::Matrix<double, 100, 1>::Ones() + e;
    int key  = 1;
    GaussianFactorGraph graph;
    Symbol s('x', 0);
    Eigen::Matrix<double, 200,2> hessian_full;
    Eigen::Matrix<double, 100 ,2> jacobian_full;
    for (int i = 0 ; i < N ; i++){
        Matrix12 A_i ;
        A_i << x[i], 1;
        Matrix22 AtA = A_i.transpose()*A_i;
        jacobian_full.row(i) = A_i;

        JacobianFactor j(s, A_i, Vector1(y[i]),noiseModel::Diagonal::Sigmas(sigma));
        graph.add(j);
    }
    std::pair<Matrix, Vector> jac_full = graph.jacobian();
    std::pair<Matrix, Vector> hessian_fg = graph.hessian();
    std::cout << "Size of jacobian: \n" << jac_full.first.size() << std::endl;
    std::cout << " value of jacobian : \n" << jac_full.first.topRows(10) << std::endl;
    std::cout << " value of b : \n" << jac_full.second.head(10) << std::endl;
    std::cout << " Solution : \n" << graph.optimizeDensely() << std::endl;
    std::cout << " value of constructed jacobian : \n" << jacobian_full.topRows(10) << std::endl;
    std::cout << " Solution (manual) : \n "
              << (jacobian_full.transpose()*jacobian_full).inverse()*jacobian_full.transpose()*y
              << std::endl;
}
