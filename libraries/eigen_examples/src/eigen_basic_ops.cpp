#include<iostream>
#include<Eigen/Dense>

using namespace std;

int main(){
    Eigen::Matrix3f mat;
    mat << 1,2,3,4,5,6,7,8,9;
    cout << " Matrix = \n " << mat << endl;

    // Indexing operations (row major or column major)
    cout << " First row, last column - Matrix[1,2] = \n " << mat(1, 2) << endl;
    cout << " zeroth row, first column - Matrix[0,1] = \n " << mat(0, 1) << endl;

    // This method does not use range check
    cout << " First row, last column - mat.coeff(0, 1) = \n " << mat.coeff(0, 1) << endl;

}
