#include <cmath>
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <string>

using namespace std;

class Number {
private:
  int a, b;

public:
  Number(int x, int y) {
    a = x;
    b = y;
  }

  int gcd() {
    while (a !=b) {
      if (a > b)
        a = a - b;
      else
        b = b - a;
    }

    return a;
  }

  bool isPrime(int n) {
    if (n <= 1)
      return false;
    for (int i = 2; i < n; i++) {
      if (n % i == 0)
        return false;
    }
    return true;
  }
};

class MyPrimeException {
};

class MyPrimeException_i: public exception{
    string msg_;
    public:
    MyPrimeException_i(int n1, int n2){
        stringstream ss;
        ss << "one of the numbers is prime :"
            << n1
            <<","
            << n2 << endl;
        msg_ = ss.str();
    }

    virtual const char* what(){
        return msg_.c_str();
    }
};

int main(int argc, char *argv[]) {

  if (argc != 3) {
    cout << " Usage : exception_with_class n1 n2" << endl;
    exit(0);
  }

  int n1 = std::stoi(*(argv + 1));
  int n2 = std::stoi(*(argv + 2));

  Number num(n1, n2);
  try {
    if ((num.isPrime(n1) || num.isPrime(n2))) {
      throw MyPrimeException();
    }
    cout << "Greatest common divisor is = " << num.gcd() << endl;
  } catch (MyPrimeException t) {
    cout << " Caught exception"
         << " of my prime exception" << endl;
  }

  // example of prime exception inherited from std::exception
  try {
    if ((num.isPrime(n1) || num.isPrime(n2))) {
      throw MyPrimeException_i(n1, n2);
    }
    cout << "Greatest common divisor is = " << num.gcd() << endl;
  } catch (MyPrimeException_i t) {
    cout << " Caught exception"
         << " of my prime exception inherited" << endl;
  }
  return 0;
}
