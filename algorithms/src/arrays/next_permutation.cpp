#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {

public:
    void nextPermutation(vector<int>& nums) {
        // find location where the change should happen - n comparisons.
        // sort the subset of elements after swapping.
        vector<int> nums1 = nums;
        int loc = -1;
        // find the location where the next element need to be changed
        for(int i = 0; i<nums1.size()-1; i++){
            if(nums[i] < nums[i+1]){
                if (loc < i){
                    loc = i;
                }
            }
        }
        if (loc == -1){
            sort(nums.begin(), nums.end(), std::less<int>());
        }
        else{

            int swap_loc = loc+1;
            int min_positive_diff = nums[swap_loc] - nums[loc];
            for(int i=swap_loc; i< nums.size(); i++){
               if(nums[i] - nums[loc] > 0 && nums[i] -nums[loc] < min_positive_diff) {
                    min_positive_diff = nums[i] - nums[loc];
                    swap_loc = i;
               }

            }
            int temp;
            temp = nums[loc];
            nums[loc] = nums[swap_loc];
            nums[swap_loc] = temp;
            sort(nums.begin() + loc+1, nums.end());
        }

        // vector<int> subset;
        // for(int i = loc+1 ; i < nums1.size(); i++)
        //     subset.push_back(nums1[i]);

    }
};
