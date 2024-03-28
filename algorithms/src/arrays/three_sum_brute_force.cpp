#include <iostream>
#include <vector>
using namespace std;
#include <map>
#include <algorithm>

class Solution {

public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int a, b, c;
        vector<vector<int>> result;
        map<tuple<int, int, int>, int> triplet_map;
        for (int i = 0; i < nums.size(); i ++){
            a = nums[i];
            for (int j = i+1 ; j < nums.size(); j++){
                b = nums[j];
                for (int k = j+1; k < nums.size(); k++){
                    c = nums[k];
                    cout << "a =" << a << " b = " << b <<" c =" << c << endl;
                    if (a+b+c == 0){
                        //cout << "a =" << a << " b = " << b <<" c =" << c << endl;
                        vector<int> temp = {a, b, c};
                        sort(temp.begin(), temp.end());
                        cout << "Sorted : a =" << a << " b = " << b <<" c =" << c << endl;
                        tuple<int, int, int> k(temp[0], temp[1], temp[2]);
                        if (triplet_map.find(k) == triplet_map.end()){
                            triplet_map[k] = 1;
                            result.push_back({a, b, c});
                        }
                    }
                }
            }
        }
        return result;
    }
};
