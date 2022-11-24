#include <boost/lexical_cast.hpp>
#include <leet_code_function_definitions.h>
using namespace std;
namespace leetcode_algorithms {

ListNode *create_list(std::vector<int> node_entries) {
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
}
