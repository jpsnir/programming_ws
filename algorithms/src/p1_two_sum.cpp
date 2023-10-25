#include <leet_code_function_definitions.h>
using namespace std;

namespace leetcode_algorithms {
vector<int> twoSum(vector<int> &nums, int target) {
  std::vector<int> indices;
  std::map<int, int> value_index;
  for (int i = 0; i < nums.size(); i++) {
    auto [it, success] = value_index.insert({nums[i], i});
    cout << " Insertion " << it->first << ":" << (success ? "sucess" : "failed")
         << endl;
  }

  for (int i = 0; i < nums.size(); i++) {
    int remainder = target - nums[i];
    auto it = value_index.find(remainder);
    if (it->second == i)
      continue;

    if (it != value_index.end()) {
      indices.push_back(i);
      indices.push_back(it->second);
      break;
    }
  }
  return indices;
}

}; // namespace leetcode_algorithms

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cout << "Usage : ./two_sum <int1> <int2> .. <intN> <target> "
              << std::endl;
    return EXIT_FAILURE;
  }

  std::vector<int> nums;
  for (int i = 1; i < argc - 1; i++) {
    nums.push_back(boost::lexical_cast<int>(argv[i]));
  }
  int target = boost::lexical_cast<int>(argv[argc - 1]);
  std::cout << " Input entries are: \n";
  for (auto num : nums)
    std::cout << num << std::endl;
  std::cout << " target : " << target << std::endl;
  vector<int> indices = leetcode_algorithms::twoSum(nums, target);
  for (auto index : indices) {
    cout << " Element at index : " << index << ":" << nums[index] << endl;
  }

  return EXIT_SUCCESS;
}
