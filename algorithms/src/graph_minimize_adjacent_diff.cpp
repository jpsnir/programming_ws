#include <iostream>
#include <vector>

using namespace std;

bool isValid(int i, int j, int x,
        vector<vector<bool>>& visited, vector<vector<int>> &arr, long parent){
    int m = arr.size(); // number of rows
    int n = arr[0].size(); //number of columns
    if (i < 0 || j < 0 || i >= m || j >= n){
        return false;
    }

    if (i == m -1 && j == n -1)
        return true;
    visited[i][j] = true;

    // this is depth first approach.
    if(isValid(i+1, j, x , visited, arr, arr[i][j]))
            return true;
    if(isValid(i, j+1, x , visited, arr, arr[i][j]))
            return true;
    if(isValid(i-1, j, x , visited, arr, arr[i][j]))
            return true;
    if(isValid(i, j-1, x , visited, arr, arr[i][j]))
            return true;

    return false;

}

int minimumEnergyPath(vector<vector<int>> &arr){
    int start = 0, end = 10e6;
    int result = arr[0][0];

    int m = arr.size(); // number of rows
    int n = arr[0].size(); //number of columns
    while(start <= end){
        int mid = (start + end)/2;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        if (isValid(0, 0, mid, visited, arr, arr[0][0])){
                result = mid;
                end = mid -1;
        }
        else{
            start = mid + 1;
        }

    }

    return result;
}

int main(){
    vector<vector<int>> arr = {
        {1 , 2, 1},
        {2, 8, 2},
        {2,4,2},
    };

    cout << minimumEnergyPath(arr);
    return 0;
}
