#include <iostream>
#include <gtsam/inference/Key.h>
#include <gtsam/linear/Sampler.h>
#include <gtsam/linear/NoiseModel.h>

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

    // Sampler objects create samples of the noise distribution which is given
    // as an input.
    gtsam::Sampler sampler(dmPtr);
    std::cout <<  sampler.sample() << std::endl;
}
