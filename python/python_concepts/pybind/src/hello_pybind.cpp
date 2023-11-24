#include <pybind11/pybind11.h>
#include <Eigen/Dense>

namespace py = pybind11;

int add(int i, int j){

    return i+j;
}

double mean(){
    Eigen::Matrix<double, 10, 1> m = Eigen::Matrix<double,10,1>::Random();
    return m.mean();
}

PYBIND11_MODULE(example, m){
    m.doc() = "pybind11 example program";
    m.def("add",&add,"A function that adds two integers");
    m.def("mean",&mean,"A function that returns mean of values in eigen vector");
}
