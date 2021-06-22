// Swap values of two integers using pass by pointer and pass by reference
// Created by Jagatpreet Singh Nir on 5/11/20.
// NUID: 001406635
// Special compile instructions:


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
  return(0);
}
void swapR(int& c, int& d)
// Swaps the values of two variables using reference
{
    int tmp;
    tmp = c;
    c = d;
    d = tmp;
}
void swapP(int *c, int *d)
// Swaps the values of two variables using pointers
{
    int tmp;
    tmp = *c;
    *c = *d;
    *d = tmp;
}