#include <chrono>
#include <iostream>
#include <map>
using namespace std;
// top down approach
int max_rob_1(int nums[], int state, std::map<int, long> &memo) {
  if (state == 0) {
    return nums[0];
  }
  if (state == 1) {
    return max(nums[0], nums[1]);
  }
  if (memo.find(state) != memo.end()) {
    return memo[state];
  }
  int result = max(max_rob_1(nums, state - 1, memo),
                   max_rob_1(nums, state - 2, memo) + nums[state]);
  memo[state] = result;
  return result;
}

// bottom up approach
int max_rob_2(int nums[], int len) {
  long sum_rob[len];
  sum_rob[0] = nums[0];
  sum_rob[1] = max(nums[0], nums[1]);
  for (int i = 2; i < len; i++) {
    sum_rob[i] = max(sum_rob[i - 1], sum_rob[i - 2] + nums[i]);
  }

  return sum_rob[len - 1];
}
int main() {
  int nums[] = {2, 7, 9, 3, 1};
  std::map<int, long> memo;
  int result = max_rob_1(nums, 4, memo);
  std::cout << "maximum loot - (top - down approach) = " << result << std::endl;
  result = max_rob_2(nums, 5);
  std::cout << "maximum loot - (bottom - up approach) = " << result << std::endl;
}
