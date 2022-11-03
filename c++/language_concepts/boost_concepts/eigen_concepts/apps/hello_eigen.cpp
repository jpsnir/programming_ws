//
// Created by jagatpreet on 2/16/21.
//

#include <iostream>
#include <eigen3/Eigen/Dense>
#include "base_datastructures/example_methods.h"
#include <cstdlib>
#include <ctime>
using namespace std;

int main(int argc, char **argv)
{
    cout<<"The definition of the eigen matrix"<<endl;
    define_matrix();

    cout<<endl<<"definining new eigen matrix using matrix class"<<endl;
    different_constructors();

    cout<<endl<<"initializing blocks of matrix"<<endl;
    initialize_matrices();
    exit(0);
}

void define_matrix()
{
    Eigen::Matrix2d m2;
    srand(time(NULL));

    for (int i = 0; i<2;i++)
        for(int j = 0; j<2;j++)
            m2(i,j) = rand()%10 + 1;

    // using dynamic allocation
    Eigen::MatrixXd m(2,2);
    m(0,0) = 3;
    m(0,1) = 2.5;
    m(1,0) = 3;
    m(1,1) = 4.5;

    Eigen::MatrixXd m3 = Eigen::MatrixXd::Random(3,3);
    m3 = m3 + Eigen::MatrixXd::Constant(3,3,5);

    Eigen::Vector3d v(3);
    Eigen::MatrixXd v1(1,3);
    v << 1,2,3;
    v1 << 4,5,6;
    // display matrix
    std::cout<<"m="<<std::endl<<m<<std::endl;
    std::cout<<"m2="<<std::endl<<m2<<std::endl;
    std::cout<<"m3="<<std::endl<<m3<<std::endl;
    std::cout<<"v = "<<v<<std::endl;
    std::cout<<"v1 = "<<v1<<std::endl;
}

void different_constructors()
{
    typedef Eigen::Matrix<int,5,1> Vector5i;
    typedef Eigen::Matrix<double,1,10> RowVector10d;
    RowVector10d rv1 = RowVector10d::Random(10);
    Vector5i v2;

    for (int i=0;i<v2.size();i++)
        v2(i) = rand()%10;

    cout<<"rv1 = "<<endl<<rv1<<endl;
    cout<<"v2 ="<<endl<<v2<<endl;

}
void initialize_matrices()
{
    typedef Eigen::Matrix<double,4,4> TransformationMat;
    Eigen::Matrix3d rot = Eigen::Matrix3d::Identity();
    Eigen::Vector3d trans = Eigen::Vector3d::Random();
    Eigen::RowVector3d rv_31 = Eigen::RowVector3d::Zero();
    TransformationMat T1;
    T1 << rot,trans,
         rv_31,1;

    cout << "T ="<<endl<<T1<<endl;
}
void do_arithmetic(int operation_type)
{

}
void accessing_elements()
{

}