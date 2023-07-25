#include <iostream>

#include <algorithm>
#include <memory>
#include <vector>

using namespace std;

/** @brief removes duplicates from a sorted array and change
 * the array in-place without copying to another array.
 */
int removeDuplicates(vector<int> &nums) {
  // handle edge cases first
  // In a sorted array, the consecutive elements will be checked.
  // start loc_i, loc_j = 0;
  //
  // nums[loc_i] < nums[loc_i+1]; then
  // nums[loc_j] = num[loc_i+1]
  // loc_j ++;
  int loc_j = 0;
  int prev;
  bool last = false, first = false;
  if (nums.size() < 2)
    return nums.size();

  for (auto curr : nums){
    if (!first){
        prev = curr;
        nums[loc_j] = curr;
        loc_j++;
        first=true;
        continue;
    }
  if (curr != prev){
    nums[loc_j] = curr;
    loc_j++;
    last = true;
    prev = curr;
  }
  }
  if (last){
    nums[loc_j] = nums[nums.size()-1];

  }
  return loc_j;

/*
  for (int loc_i = 0; loc_i < nums.size(); loc_i++) {
    if (nums[loc_i] < 0 && nums[loc_i + 1] >= 0) {
      if (loc_i <= nums.size() - 2) {
        nums[loc_j] = nums[loc_i];
        continue;
      } else {
        nums[loc_j] = nums[loc_i];
        nums[loc_j++] = nums[loc_i + 1];
      }
        loc_j++;
      }
       if (nums[loc_i] < nums[loc_i + 1]) {
        if (loc_i <= nums.size() - 2) {
          nums[loc_j] = nums[loc_i];
        } else {
          nums[loc_j] = nums[loc_i];
          nums[loc_j++] = nums[loc_i + 1];
        }
          loc_j ++;
      }
    }

    return loc_j;
    */
  }

  int main() {
    vector<int> nums{1,1, 2};
    int k = removeDuplicates(nums);
    std::cout << " Final number of elements" << k << std::endl;
    for (int e = 0; e <k; e++)
      std::cout << nums[e] << std::endl;
  }
