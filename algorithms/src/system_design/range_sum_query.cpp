#include <iostream>
#include <vector>
#include <map>
#include <tuple>
using namespace std;
class NumArray{
    public:
        NumArray(vector<int>& nums){
            this->nums = nums;
        }

        int sumRange(int left, int right){
            pair<int, int> left_right = {left, right};
            if (sum_cache.find(left_right) != sum_cache.end()){
                return sum_cache[left_right];
            }
            int sum = 0;
            for(int i = left - 1; i < right ; i++){
                sum += nums[i];
            };

            sum_cache[left_right] = sum;
            return sum;
        }

    private:
        vector<int> nums;
        map<pair<int, int>, int> sum_cache;

};
