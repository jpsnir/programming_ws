#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int> a = {1, 2, 3, 4, 5, 6, 7 , 8 };
    auto v = find(a.begin(), a.end(), 2);
    cout << " Element found : " << *v << endl;
}
