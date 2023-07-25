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

// Problem 2
long form_number(ListNode* l);
std::vector<int> twoSum(std::vector<int> &nums, int target);
/* @brief addTwoNumbersLong can add two lists containing numbers w
* which contain less than 16 digits. 
*/
ListNode* addTwoNumbersLong(ListNode* l1, ListNode* l2);

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
ListNode* create_list(std::vector<int> node_entries);
ListNode* create_list(long num);
int display_list_elements(ListNode* l1);
};
#endif
