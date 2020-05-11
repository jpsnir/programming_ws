/*
This program explains the concept of local and global variables
Author: Jagatpreet Singh 
Date: 11 - may - 2020
*/

#include <iostream>
#include <cstdlib>

using namespace std;
int a{1};
void function1();
void function2();
int main(int argc, char** argv)
{
   cout<<"The value of a :"<<a<<endl;
   function1();
   cout<<"\n The value of a after function 1  execution:"<<a<<endl;
   function2();
   cout<<"\n The value of a after function 2 execution:"<<a<<endl;
}


/*
function1 uses a local value of variable a
*/
void function1()
{
   int a{10};
   cout<<"\nThe value of a in local function:"<<a<<endl; 
}

/*
function2 uses the global value of variable a 
*/
void function2()
{
   cout<<"\n Enter a number to be added to global a :";
   cin>>a;
}
