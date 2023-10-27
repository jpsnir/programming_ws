#include <gtsam/base/Matrix.h>
#include <gtsam/base/Vector.h>
#include <gtsam/linear/NoiseModel.h>
#include <iostream>
#include <cmath>
#include <gtsam/geometry/Pose2.h>
#include <gtsam/slam/BetweenFactor.h>
#include <gtsam/inference/Key.h>
#include <gtsam/inference/Symbol.h>
#include <gtsam/geometry/Point2.h>
#include <gtsam/base/VectorSpace.h>
#include <gtsam/nonlinear/Values.h>
#include <gtsam/nonlinear/ISAM2.h>
#include "SFMdata.h"
#include <gtsam/nonlinear/NonlinearFactorGraph.h>
#include <gtsam/slam/ProjectionFactor.h>

using namespace gtsam;

int main(int argc, char *argv[]){

 std::cout << " Hello GTSAM" << std::endl;
 gtsam::Cal3_S2::shared_ptr K(new gtsam::Cal3_S2(50.0, 50.0, 0.0, 50.0, 50.0));
 auto measurementNoise = gtsam::noiseModel::Isotropic::Sigma(2,1.0);
 std::vector<gtsam::Point3> points = createPoints();
 std::vector<gtsam::Pose3> poses = createPoses();
 gtsam::ISAM2Params parameters;
 parameters.relinearizeThreshold = 0.01;
 parameters.relinearizeSkip = 1;
 gtsam::ISAM2 isam(parameters);
 gtsam::NonlinearFactorGraph graph;
 gtsam::Values initialEstimate;

 for (size_t i=0; i < poses.size(); ++i){
    for (size_t j=0; j < points.size();++j) {
        gtsam::PinholeCamera<Cal3_S2> camera(poses[i], *K);
        Point2 measurement = camera.project(points[j]);
        graph.emplace_shared<GenericProjectionFactor<Pose3,Point3,Cal3_S2>>(measurement,measurementNoise, Symbol('x',i), Symbol('l',j), K);
    }
    static Pose3 kDeltaPose(Rot3::Rodrigues(-0.1,0.2,0.25),Point3(0.05, -0.10, 0.20));
    initialEstimate.insert(Symbol('x', i), poses[i]*kDeltaPose);
    if (i==0) {
        static auto kPosePrior = noiseModel::Diagonal::Sigmas(
                (gtsam::Vector(6) << gtsam::Vector3::Constant(0.1), Vector3::Constant(0.3)).finished());
        graph.addPrior(Symbol('x',0), poses[0],kPosePrior);
        static auto kPointPrior = noiseModel::Isotropic::Sigma(3, 0.1);
        graph.addPrior(Symbol('l',0), points[0], kPointPrior);

        static Point3 kDeltaPoint(-0.25, 0.20, 0.15);
        for (size_t j = 0; j < points.size(); ++j)
            initialEstimate.insert<Point3>(Symbol('l',j),points[j] + kDeltaPoint);
    }
    else {
        isam.update(graph, initialEstimate);
        isam.printStats();
        Values currentEstimate = isam.calculateEstimate();
        std::cout << "************************************************" << std::endl;
        std::cout << "Frame " << i << ":" << std::endl;
        currentEstimate.print("Current estimate: ");
        graph.resize(0);
        initialEstimate.clear();
    }
 }

 return 0;
}
