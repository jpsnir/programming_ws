#include "bits/stdc++.h" // includes every c library automatically, saves time. but not good for optimal code
#include <cstdlib> //standard c library functions provided in c++. Very helpful!!

using namespace std;

string rtrim(const string &str) {
    string s(str);
    cout<<"String begin "<<s.rbegin()<<endl;

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

int main(){
    printf("Hello world! \n"); // c function Include \n for new line in printf
    printf("The number = %.2f \n",stod("100.54 + 50")); //stod takes in only first segment of the string, ignores everything after whitespace.
    cout<<rtrim("100     ")<<endl;
    cout<<rtrim("       100     ")<<endl;
}