#include <iostream>
#include <vector>
#include <list>
#include <math.h>

using namespace std;

void dfs(int index, const vector<int> nums, list<int> current_subset, list<list<int>> &subsets){
    if(index==nums.size()){
        subsets.push_back(current_subset);
        return;
    }

    // append element
    current_subset.push_back(nums[index]);
    dfs(index+1, nums, current_subset, subsets);

    //remove current element
    current_subset.pop_back();
    dfs(index+1, nums, current_subset, subsets);
}

int main(){
    std::vector<int> nums = {1,2,3,4,5};
    std::list<list<int>> subsets = {};
    std::list<int> current_subset = {};
    dfs(0, nums,current_subset, subsets);
    for(auto ss: subsets){
        std::cout << "{";
        for(auto e: ss){
            std::cout << e << "," ;
        }
        std::cout << "}\n" ;
    }
    cout << "Number of subsets = " << subsets.size() << endl;
    cout << "Combinations = " << pow(2, nums.size()) << endl;
}