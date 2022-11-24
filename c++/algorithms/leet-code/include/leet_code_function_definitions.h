#ifndef LEETCODE_FUNCTION_DEFINITIONS_HPP
#define LEETCODE_FUNCTION_DEFINITIONS_HPP

#include <boost/lexical_cast.hpp>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>

// Problem 1
namespace leetcode_algorithms {
struct ListNode{
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

std::vector<int> twoSum(std::vector<int> &nums, int target);
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
};
#endif
