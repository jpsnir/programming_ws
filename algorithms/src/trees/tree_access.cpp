#include <iostream>
#include <cmath>
#include <iomanip>
#include <cassert>
#include <cstdio>
// Binary tree implemented with a goal to understand
// the access algorithms in tree.

enum Traversal{
    IN_ORDER = 0,
    PRE_ORDER = 1,
    POST_ORDER = 2,
};

class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(const int data){
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
    Node* assign_left(Node* l){
        left = l;
        return this;
    }
    Node* assign_right(Node* r){
        right = r;
        return this;
    }
//    void traverse_tree(const Traversal type=IN_ORDER);
    static void inorder_traversal(Node* root);
    static void preorder_traversal(Node* root);
    static void postorder_traversal(Node* root);
};

/*
void Node::traverse_tree(const Traversal type){
    switch(type){
        case IN_ORDER:
            inorder_traversal();
            break;
        case PRE_ORDER:
            preorder_traversal();
            break;
        case POST_ORDER:
            postorder_traversal();
            break;
        default:
            std::cout << " This case is not implemented.\n" << std::endl;
    }
}
*/

void Node::inorder_traversal(Node* root){
    // 1. traverse the left subtree (inorder)
    // 2. visit the root
    // 3. traverse the right subtree (inorder)
    // recursive access of subtree in a sequence.

    // check if it is the leaf node
    if (root == nullptr)
        return;

    // left subtree
    inorder_traversal(root->left);
    printf("%d,",root->data); // current node,
    inorder_traversal(root->right);
}

void Node::preorder_traversal(Node* root){
    // 1. visit the root
    // 2. traverse the left subtree (preorder)
    // 3. traverse the right subtree (preorder)
    // recursive access of subtree in a sequence.

    // check if it is the leaf node
    if (root == nullptr)
        return;

    // left subtree
    printf("%d,",root->data); // current node,
    preorder_traversal(root->left);
    preorder_traversal(root->right);

}

void Node::postorder_traversal(Node* root){
    // 1. traverse the left subtree (preorder)
    // 2. traverse the right subtree (preorder)
    // 3. visit the root
    // recursive access of subtree in a sequence.

    // check if it is the leaf node
    if (root == nullptr)
        return;

    // left subtree
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    printf("%d,",root->data); // current node,

}


int main(){
    Node* root = new Node(1);
    Node* n1 = new Node(2);
    Node* n2 = new Node(3);
    Node* n3 = new Node(4);
    Node* n4 = new Node(5);
    Node* n5 = new Node(6);
    Node* n6 = new Node(7);
    n1->assign_left(n3)->assign_right(n4);
    n2->assign_left(n5)->assign_right(n6);
    root->assign_left(n1)->assign_right(n2);
    std::cout << " In order traversal : \n";
    Node::inorder_traversal(root);
    printf("\n");

    std::cout << " Pre order traversal : \n";
    Node::preorder_traversal(root);
    printf("\n");

    std::cout << " Post order traversal : \n";
    Node::postorder_traversal(root);
    printf("\n");

    delete n6;
    delete n5;
    delete n4;
    delete n3;
    delete n2;
    delete n1;
    delete root;
}
