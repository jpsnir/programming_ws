#include <iostream>
#include <type_traits>

class A{};
class B:A {};
int main(){
    std::cout << std::is_same<A, float>::value << "\n";
    std::cout << std::is_same<A, A>::value << "\n";
    std::cout << std::is_same<A, B>::value << "\n";
}
