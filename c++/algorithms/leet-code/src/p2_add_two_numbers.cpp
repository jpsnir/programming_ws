#include <boost/lexical_cast.hpp>
#include <leet_code_function_definitions.h>
using namespace std;
namespace leetcode_algorithms {

ListNode* create_list(long num){
  ListNode *l1 = new ListNode();
  ListNode *firstNode = l1;
  while (true){
    int last_digit = num % 10;
    //cout << last_digit;
    l1->val = last_digit;
    num = num / 10;
    if (num == 0)
        break;
    l1->next = new ListNode();
    l1 = l1->next;
  }
  return firstNode;
}

long form_number(ListNode* l){
  
  // first digit is first node and
  // last digit is last node.
  
  if (l==nullptr)
    return 0;
  long number = 0;
  int digit_count = 0;
  while(l!=nullptr){
    number += l->val*pow(10, digit_count);
    l = l->next;
    digit_count++ ;
  }
  return number;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){

  if (l1 != nullptr && l2 == nullptr){
    return l1;
  }

  if (l1 == nullptr && l2 != l2){
    return l2;
  }
  //0. Initialize carry_over=0; result_node;
  int carry_over = 0;
  ListNode* l = new ListNode();
  ListNode* resultNode = l;
  
  while (true){
  //1. Get digits from each linked list (d1, d2) and add them
    int d1, d2, digit;

    // end of both linked lists
    if (l1 == nullptr && l2 == nullptr)
      break;

    // end of l1    
    if (l1 != nullptr)
     d1 = l1-> val;
    else 
     d1 = 0;
     
    // end of l2
    if (l2 != nullptr)
     d2 = l2-> val;
    else 
     d2 = 0;

    //2. if (d1 + d2) >= 10; current_node->value = 0; carry_over = 1
    int sum = d1 + d2 + carry_over;
    carry_over = sum/10;
    digit = sum % 10;
    cout << "Sum of digits " << d1 << " + " << d2 << "=" << digit <<endl;

    // 3. assign digits and update
    l->val = digit;
    if (l1 != nullptr)
      l1 = l1->next;
    
    if (l2 != nullptr)
      l2 = l2->next;

    // only create new node when atleast one of them is not a null pointer
    if (l1 != nullptr || l2 != nullptr){
      l->next = new ListNode();
      l = l->next;
    }
  }
  // create node for assigning carry over as a digit.
  if (carry_over != 0)
    l->next = new ListNode(carry_over);
  return resultNode;
}

ListNode* addTwoNumbersLong(ListNode* l1, ListNode* l2){
  if (l1 != nullptr && l2 == nullptr){
    return l1;
  }

  if (l1 == nullptr && l2 != l2){
    return l2;
  }

   // 1. form numbers from linked lists
  long num1, num2, result;
  num1 = form_number(l1);
  num2 = form_number(l2);

  // 2. add
  result = num1 + num2;
  cout << " The result of addition of " << num1 << " + " << num2 << "=" << result << endl;
  // 3. make a linked list again from the number.
  return create_list(result);
}

ListNode* create_list(std::vector<int> node_entries) {
  if (node_entries.size() == 0){
    cerr << " No elements " << endl;
    return nullptr;
  }

  ListNode *firstNode = new ListNode{node_entries[0], nullptr};
  ListNode *currNode = firstNode;
  for (int i = 1; i < node_entries.size(); i++) {
    cout << "Address current node : " << currNode << endl;
    currNode->next = new ListNode(node_entries[i], nullptr);
    currNode = currNode->next;

  }
  return firstNode;
}

int display_list_elements(ListNode* l1){
  if (l1==nullptr){
    cerr << " Empty list" << endl;
    return EXIT_FAILURE; 
  }
  ListNode* currNode = l1;
  cout << " List elements are : " << endl;
  while (currNode != nullptr){
    cout << currNode->val << ",";
    currNode = currNode->next;
  }
  cout << endl;
  return EXIT_SUCCESS;
}

}; // namespace leetcode_algorithms

int main(int argc, char* argv[]){
    if (argc != 3){
        cout << " Usage: ./problem_2 <num1> <num2> " << endl;
        return EXIT_FAILURE;
    }
    vector<int> inputs{0, 0};
    inputs[0] = boost::lexical_cast<int>(argv[1]);
    inputs[1] = boost::lexical_cast<int>(argv[2]);
    for (auto in : inputs)
        cout << " Inputs are : " << in << endl;
    std::vector<vector<int>> node_entries_list;
    for (auto in : inputs){
        vector<int> node_entry;
        while (in != 0){
            int last_digit = in % 10;
            //cout << last_digit;
            node_entry.push_back(last_digit);
            in = in / 10;
        }
        node_entries_list.push_back(node_entry);
    }
   std::vector<leetcode_algorithms::ListNode*> nodes;
   for (int i = 0; i <  node_entries_list.size(); i++){
    nodes.push_back(leetcode_algorithms::create_list(node_entries_list[i]));
    leetcode_algorithms::display_list_elements(nodes[i]);
   }

   leetcode_algorithms::ListNode* l = addTwoNumbers(nodes[0], nodes[1]);
   leetcode_algorithms::display_list_elements(l);
}
