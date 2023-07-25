#include <iostream>
#include <string>

int main(int argc, char * argv[]){
    std::cout <<"Number of arguments:"<<argc<<std::endl;
    for (int i = 1; i < argc; i++){
        std::cout << "input arguments are :" << *(argv + i) << std::endl;
    }
    int x = 121;
    int number = 0;
    int test_num = abs(x);
    while(test_num > 0){
        int digit = test_num%10;
        test_num = test_num/10;
        number = number*10 + digit;
    }
    std::cout << "Inverted number:" << number << "original number" << abs(x)
    << std::endl;
    std::cout << "Inverted number - original number" << number - abs(x) <<
    std::endl;
    if (abs(x) == number && x >=0){
        std::cout << " number is palindrome" << std::endl;
        return true;
    }
    else {
        std::cout << " number is not palindrome" << std::endl;
        return false;
        }
}
