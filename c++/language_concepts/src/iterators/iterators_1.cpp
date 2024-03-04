#include <iostream>
#include <iterator>
#include <vector>

// NOTE: Learn about iterators
// a. interface of iterators.
// b. looping
// c.
using namespace std;

int main(){
    vector<int> arr = {1,2,3,4,5};
    vector<int>::iterator it;
    for (it= arr.begin(); it != arr.end(); it++)
        cout<< *it << ",";
    cout << endl;

    it = arr.begin();
    cout << " first element: " << *it << endl;
    advance(it, 1);
    cout << " second element : " << *it << endl;
    advance(it, 2);
    cout << " fourth element ( advanced by 2 steps) " << *it << endl;

    auto start = arr.begin();
    it = std::next(start, 3);
    cout << " Next operation : (start) = " << *start << ", iterator = " << *it << endl;

    vector<int> ar = {10, 20, 30};
    vector<int>::iterator ptr = arr.begin();
    std::advance(ptr, 3);
    std::copy(ar.begin(), ar.end(), inserter(arr, ptr));
    for(auto e: arr)
        cout << e << "," ;
    cout <<endl;

}
