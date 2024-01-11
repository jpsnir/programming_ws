#include <iostream>
#include <string>
#include <cstring>
void print(const std::string& s){
    std::cout << &s << std::endl;
}
int main(){
    // c style string
    // strings are generally im-mutable
    // this has null termination character.
    const char* name1 = "jagat";
    // using null termination character, cout knows where to terminate.
    std::cout << "Name = " << name1 << std::endl;
    // if it is a character array that is mutable
    char name2[5] = {'j','a','g','a','t'};
    std::cout << " Name 2 is not null terminated" << std::endl;
    std::cout << "Name2 = " << name2 << " length = " << strlen(name2) << std::endl;

    // defines const char pointer inside.
    std::string name3 = "jagat";
    std::cout << name3 << std::endl;
    bool contains = name3.find("ga") != std::string::npos;
    std::cout << " contains ja: " << contains << std::endl;
    std::cout << "address in main : " << &name3 << std::endl;
    print(name3);

}
