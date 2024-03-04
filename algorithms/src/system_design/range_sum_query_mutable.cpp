#include <iostream>
#include <vector>
#include <map>
using namespace std;

// TODO: Improve design by a different caching strategy
class Numarray{
    public:
        Numarray(vector<int> &nums){
            this->nums = nums;
            int sum = 0;
            compuate_sum_cache();
        }

        void update(int index, int val){
            this->nums[index] = val;
            compuate_sum_cache();
        }

        int sumRange(int left, int right){
            return sums_ind[right] - sums_ind[right];
        }
    private:
        void compuate_sum_cache(){
            int sum = 0;
            for(int i =0; i < nums.size(); i++){
                sum += nums[i];
                sums_ind[i] = sum;
            }
        }
        vector<int> nums;
        map<int, int> sums_ind;
};
