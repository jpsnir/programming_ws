#include <iostream>
/*
 * Create a mergable stack using linked list.
 * Implements a custom stack data structure for dealing
 * with the operation of merging two stacks in
 * O(1) complexity.
 * @author: jagatpreet
 * Adapted from: geeksforgeeks
 */

class node {
    public:
        int data;
        node *next;
};

class mergable_stack{
    public:
        node* head;
        node* tail;

        mergable_stack(){
            head = NULL;
            tail = NULL;
        }
};

mergable_stack* create(){
    // allocate memory on heap
    mergable_stack* ms = new mergable_stack();
    return ms;
}

void push(int data, mergable_stack* ms){
    node* temp = new node();
    temp->data = data;
    std::cout << " temp's next address " << temp->next << std::endl;
    // first connect the temp node to existing head
    temp->next = ms->head;
    if (ms->head == NULL){
        ms->tail = temp;
    }
    // then update the head to temp
    ms->head = temp;
    std::cout << " Push operation \n" ;
    std::cout << "stack tail : " << ms->tail->data <<
        ", stack head : " << ms->head->data;
    std::cout << std::endl;
}

int pop(mergable_stack* ms){
    if(ms->head == NULL){
        std::cout << "stack underflow " << std::endl;
        return 0;
    }
    else {
        node* temp = ms-> head;
        ms->head = ms->head->next;
        int popped = temp->data;
        // since its on heap, delete that address.
        delete temp;
        return popped;
    }
}

void merge(mergable_stack* ms1, mergable_stack* ms2){
    if(ms1->head == NULL){
        ms1->head = ms2->head;
        ms1->tail = ms2->tail;
        return;
    }

    std::cout << "ms1 - tail " << ms1->tail->next << ", and " << ms2->head <<"\n";
    std::cout << "ms1 - tail " << ms1->tail << ", and " << ms2->tail <<"\n";
    ms1->tail->next = ms2->head;

    // Even if I comment out the line below
    // the result does not change.
    // Donot understand its purpose
    // Why should we connect the tail of ms1 to ms2 after merge?
    ms1->tail = ms2->tail;
}

void display(mergable_stack* ms){
    node* temp = ms->head;
    while (temp != NULL){
        std::cout << temp -> data << ",";
        temp = temp->next;
    }
}

int main() {
    mergable_stack* ms1 = create();
    mergable_stack* ms2 = create();
    push(3, ms1);
    push(2, ms1);
    push(1, ms1);

    push(6, ms2);
    push(5, ms2);
    push(4, ms2);

    merge(ms1, ms2);
    display(ms1);
    std::cout << "\n";

}
