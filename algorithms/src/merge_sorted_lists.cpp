#include <algorithm>
#include <forward_list>
#include <iostream>
#include <iterator>
#include <vector>

// Create a singly linked list with the struct definition
// Implement the following :
// - insert
// - remove
// - end
// - front

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// TO create a linked list we need to allocate each node on a heap
// and get the pointer of the memory location in the heap in the stack of
// program memory.
ListNode *create_linked_list(std::vector<int> entries) {
  ListNode *head;

  // starting from the last entry in the vector.
  // N <- N-1 <- N-2 .... <- 0
  // The above describes the scheme in which we will allocate
  // the nodes.
  // 1. allocate node on heap using new and store the address in listnode
  // pointer.
  // 2. Iterate to next value and assign both address and value
  // 3. repeat 2

  // Iterators .end() function gives us an element just next to the last element
  // and therefore we need to subtract 1.
  if (entries.empty())
    return nullptr;

  for (std::vector<int>::iterator it = entries.end() - 1; it >= entries.begin();
       it--) {
    int val = *it;
    if (it == entries.end() - 1) {
      head = new ListNode(val, nullptr);
    } else {
      head = new ListNode(val, head);
    }
    std::cout << "current node address = " << head << "- value of current - "
              << head->val << ", linked to :" << head->next << std::endl;
  }
  return head;
}

void display_linked_list_elements(ListNode *n1) {
  // 1. assign first node address to temporary variable
  // 2. Iterate temp until null ptr
  // 3. update temp = temp -> next ( to go to next node)
  std::cout << " Linked list " << std::endl;
  if (n1 == nullptr)
    std::cout << " Linked List empty" << std::endl;
  else {
    ListNode *head = n1;
    do {
      std::cout << head->val << std::endl;
      head = head->next;
    } while (head);
  }
}

ListNode *mergeTwoLists(ListNode *n1, ListNode *n2) {
  /*  - - - - - - - -
  *   n1
  *   + + + + +
  *   n2
  *  // Do with a constant memory allocation without creating a new list
  * 1. assign lowest = n2
  * if (n2->val <= n1->val)
  *   lower = n2, possible_next1 = n1
  * else
  *    lower = n1; possible_next1 = n2
  * 2. compare next element with bigger of possible_next2 = lower-> next
  * if( possible_next2->val <= possible_next1->val)
  *  lower = possible_next2; possible_next2 = lower-> next;
  * else
  * temp1 = lower->next; temp2 = possible_next1->next1
  * lower->next = possible_next1; possible_next1->next =  temp1;
  *
  * then n1-> next = n2
  * we need temp variables:

  */

  std::cout << "Merging two linked lists " << std::endl;
  ListNode *head = nullptr;
  ListNode *tail = nullptr;

  if (n1 == nullptr)
    return n2;
  if (n2 == nullptr)
    return n1;

  // start head and tail with the lowest element

  tail = new ListNode();
  if (n1->val <= n2->val) {
    head = new ListNode(n1->val, tail);
    n1 = n1->next;
  } else {
    head = new ListNode(n2->val, tail);
    n2 = n2->next;
  }

  while (true) {
    // Different length of lists
    // When one list ends, we copy all the nodes to merged list in
    // sequence.
    if (n1 == nullptr && n2 == nullptr)
      break;

    if (n1 == nullptr) {
      std::cout << "n1 null" << std::endl;
      tail->val = n2->val;
      n2 = n2->next;
      if(n2){
      tail->next = new ListNode();
      tail = tail->next;
      }
      continue;
    }

    if (n2 == nullptr) {
      std::cout << "n2 null" << std::endl;
      tail->val = n1->val;
      n1 = n1->next;
      if (n1){
      tail->next = new ListNode();
      tail = tail->next;}
      continue;
    }

    if (n1 && n2) {
      if (n2->val <= n1->val) {
        std::cout << "n2" << std::endl;
        tail->val = n2->val;
        tail->next = new ListNode();
        n2 = n2->next;
        tail = tail->next;
      } else {
        std::cout << "n1" << std::endl;
        tail->val = n1->val;
        tail->next = new ListNode();
        n1 = n1->next;
        tail = tail->next;
      }
    }

   std::cout << " Entry: " << tail->val << ", address : " << tail->next
              << std::endl;
  }
  return head;
}

int main(int argc, char *argv[]) {
  std::forward_list<int> l1, l2;
  ListNode *n1 = create_linked_list(std::vector<int>{1, 2, 4});
  ListNode *n2 = create_linked_list(std::vector<int>{1, 3, 4});
  display_linked_list_elements(n1);
  display_linked_list_elements(n2);
  ListNode *n3 = mergeTwoLists(n1, n2);
  display_linked_list_elements(n3);
  display_linked_list_elements(mergeTwoLists(n1, n2));
}
