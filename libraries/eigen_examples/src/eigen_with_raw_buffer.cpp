#include<iostream>
#include<eigen3/Eigen/Dense>
#include<vector>

using namespace std;

// referring to the same data in heap
// eigen vaectors can be directly initialized with
// c style arrays or the map class can be to used.
// no new memory is allocated. All these methods are
// just mapping the std vector to be used with
// eigen interface.
// no copy only pointing to the data and get the interface.
int main(){
    int x[5] = {1, 2, 3, 4, 5};
    vector<int> v1;
    v1.reserve(5);


    Eigen::Map<Eigen::VectorXi> X(x, 5);

    // creating a copy - one line copy to eigen matrix
    Eigen::VectorXi v2 = Eigen::Map<Eigen::VectorXi>(x, 5);
    Eigen::VectorXi v3 = Eigen::Map<Eigen::VectorXi, Eigen::Unaligned>(x, 5);

    // copy back to vector
    std::vector<int> x2(v2.data(), v2.data() + v2.cols()*v2.rows());
    for (int i = 0; i < 5; i++){
        cout << " values: "<< i << ":"
            << " original = " << x[i]
            << ", mapped  = " << X[i]
            << ", copied to eigen =" << v2[i]
            << ", copied to eigen - unaligned =" << v3[i]
            << ", copied back to vector =" << x2[i]
            << std::endl;
    }

}
