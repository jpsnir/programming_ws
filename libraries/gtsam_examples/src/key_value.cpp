#include <iostream>
#include <gtsam/inference/Key.h>
#include <gtsam/linear/Sampler.h>
#include <gtsam/linear/NoiseModel.h>
#include <gtsam/3rdparty/Eigen/Eigen/Core>
#include <vector>

int main() {
    gtsam::Matrix11 R;
    R << 1;
    gtsam::Vector4 v;
    v << 1,1,1,1;
    // static factory methods for creating different noise models.
    gtsam::SharedGaussian gmPtr = gtsam::noiseModel::Gaussian::Covariance(R);
    gtsam::SharedNoiseModel nmPtr = gtsam::noiseModel::Gaussian::Covariance(R);
    gtsam::SharedDiagonal dmPtr = gtsam::noiseModel::Diagonal::Sigmas(v);
    std::cout << gmPtr->covariance() << std::endl;
    std::cout << dmPtr->covariance() << std::endl;
    gtsam::Vector4 input{1,2,1,1};
    std::cout << " Whiten error = \n " <<     gmPtr->whiten(input) << std::endl;
    // Sampler objects create samples of the noise distribution which is given
    // as an input.
    gtsam::Sampler sampler(dmPtr);
    for(int i = 0; i < 10; i++){
    std::cout <<  sampler.sample() << std::endl;
    std::cout << "-----------\n";
    }

    // create vector from the equation.
    // Y = aX + b + E
    // x - nx1 vector
    // A - scalar, b - scalr, E - nx1 normal random vector
    Eigen::VectorXd X;
    Eigen::VectorXd Y;
    Eigen::VectorXd E;

    // This helps us to understand how we can use gtsam for vectorized
    // operations
    // The problem and noise models thinking in terms of gtsam classes
    // will be helpful to write better code that exploits gtsam.
    Eigen::Matrix<double, 100, 1> d = Eigen::Matrix<double, 100, 1>::Ones();
    gtsam::SharedDiagonal dm = gtsam::noiseModel::Diagonal::Sigmas(d);
    sampler = gtsam::Sampler(dm);
    E = sampler.sample();
    X = Eigen::VectorXd::LinSpaced(100, 1, 100);
    Y = 0.5*X + 1.0*Eigen::VectorXd::Ones(100) + E;
    std::vector<double> l_vec(100);
    for (int i = 1; i <=100; i++){
        l_vec[i] = i;
    }
    //Eigen::VectorXd X_(l_vec.data());

    // trying to learn single statement operations and thinking
    // with eigen in terms of vector operations
    std::cout << " Y = " << Y.segment(10, 20)
              << "\n ----------------- \n "
    //         << " X- = " << X_.segment(10, 20)
              << "\n-----------------\n"
              << " X = " << X.segment(10,20) << std::endl;


}
