#include <iostream>

using namespace std;

void swapR(int& a, int& b);
void swapP(int *a, int *b);
int main(int argc, char **argv)
{
  int a(1);
  int b(45);
  cout<<"Value of a ="<<a<<" and  b ="<<b<<" inside main function before swapping"<<endl;
  cout<<"---------------------Swap by reference start----------------------------------\n";
  swapR(a,b);
  cout<<"Value of a ="<<a<<" and  b ="<<b<<" inside main function after swapping using pass by reference"<<endl;
  
  cout<<"xxxxxxxxxxxxxxxxxxxxxxxxx Swap by reference complete xxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
  
  cout<<"\nValue of a ="<<a<<" and  b ="<<b<<" inside main function before swap using pointers"<<endl;

  cout<<"\n---------------------Swap by pointer start-------------------------------\n";
  swapP(&a,&b);
  cout<<"Value of a ="<<a<<" and  b ="<<b<<" inside main function after swap using pointers"<<endl;
  cout<<"xxxxxxxxxxxxxxxxxxxxxxxxx Swap by pointer complete xxxxxxxxxxxxxxxxxxxxxxxxx\ns";
}
void swapR(int& a, int& b)
{
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}
void swapP(int *a, int *b)
// Swaps the values of two variables using pointers
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}