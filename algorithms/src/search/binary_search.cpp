#include <iostream>

using namespace std;

int binarysearch(int arr[], int l, int r, int x){
    while(l <= r){
        int m = l + (r - l)/ 2;

        cout << arr[m] << endl;
        if(arr[m] == x)
            return m;

        if(arr[m] < x)
            l = m + 1;
        else
            r = m -1;
    }
    return -1;

}

int main(){

    int arr[] = {2, 3, 4, 10, 40};
    int x = 10;
    int n = sizeof(arr)/sizeof(arr[0]);
    int result = binarysearch(arr, 0, n-1, x);
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ,";
    }
    cout << endl;
    (result == -1)
        ? cout << "Element is not present in array"
        : cout << "Element is present at the index: " << result;
    cout << endl;
    return 0;
}
