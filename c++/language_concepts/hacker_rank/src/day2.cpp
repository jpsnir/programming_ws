#include <iostream>
#include <iomanip>


using namespace std;
int main()
{
    int a = 1;
    double b;
    cin>>b;
    cout<<fixed << setprecision(2)<< a+b << endl;
    cout<<scientific<<setprecision(2)<<a+b<<endl;
    printf("%2.2f \n",a+b);
    return 0;
}