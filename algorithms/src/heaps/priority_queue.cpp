#include <iostream>
#include <queue>

using namespace std;
// NOTE: This does give the elements in order from lowest to highest.
// We are keeping only k largest elements in the priority queue at all times.
// At the end of the vector, there should remain only top k elements.
// Since these are the top k maximum just pop them all.

void k_largest(vector<int> &v, int N, int K){
    priority_queue<int, vector<int>,greater<int>> pq;
    for (int i = 0; i < N; ++i){
        pq.push(v[i]);

        if(pq.size() > K){
            pq.pop();
        }
    }

    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}

int main(){
    vector<int> arr = {11, 3, 2, 1, 15, 5, 4, 45, 88, 96, 50, 45};
    int n = arr.size();
    int k = 3;
    cout << k << "largest elements are : " ;
    k_largest(arr, n, k);
}
