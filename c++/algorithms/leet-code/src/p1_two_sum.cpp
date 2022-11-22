#include <leet_code_function_definitions.h>
namespace leetcode_algorithms{
using namespace std;
vector<int> twoSum(vector<int> &nums, int target){
    vector<int> indices{0};
    return indices;
}

};

int main(int argc, char* argv[]){
  if (argc < 2){
    std::cout << "Usage : ./two_sum <int1> <int2> .. <intN> <target> " <<
    std::endl;
    return EXIT_FAILURE; 
  }

  std::vector<int> nums;
  for (int i = 1; i < argc - 1 ; i ++){
   nums.push_back(boost::lexical_cast<int>(argv[i]));
  }
  int target = boost::lexical_cast<int>(argv[argc - 1]);
  std::cout << " Input entries are: \n" ;
  for (auto num : nums)
    std::cout << num << std::endl;
  std::cout << " target : " << target << std::endl;
  return EXIT_SUCCESS;
}
