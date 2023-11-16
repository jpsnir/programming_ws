#include <iostream>
#include <Eigen/Core>
class RandomSequence: public Eigen::VectorXd
{
public:
    RandomSequence(void):Eigen::VectorXd(){}

    template<typename OtherDerived>
    RandomSequence(const Eigen::MatrixBase<OtherDerived>& other): Eigen::VectorXd(other)
    {
    }


    template<typename OtherDerived>
    RandomSequence& operator=(const Eigen::MatrixBase<OtherDerived>& other){
        this->Eigen::VectorXd::operator=(other);
        return *this;
    }
};
int main(){
    Eigen::Matrix<float, 2,2> m;
    m << 1,2,3,4;
    m.printAddOnName();
    std::cout << m << std::endl;
    RandomSequence v = RandomSequence::Ones(4);
    v(2) += 10;
    v = 2*v;
    std::cout << v << std::endl;
}
