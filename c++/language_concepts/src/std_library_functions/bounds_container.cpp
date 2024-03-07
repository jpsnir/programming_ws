#include <algorithm>
#include <iostream>
#include <list>
#include <vector>


using namespace std;

int main(){

    int arr[] = {5, 5, 5,6,6, 7, 8, 7, 7};
    vector<int> varr(arr, arr+ 7);
    std::sort(varr.begin(), varr.end());
    vector<int>::iterator lower, upper;
    for (auto val: varr){
        cout << val << "," ;
    }
    cout << endl;
    lower = lower_bound(varr.begin(), varr.end(), 6);
    upper = upper_bound(varr.begin(), varr.end(), 6);
    cout << " lower bound for 6 at index " << (lower - varr.begin()) << endl;
    cout << " Upper bound for 6 at index " << (upper - varr.begin()) << endl;
}
