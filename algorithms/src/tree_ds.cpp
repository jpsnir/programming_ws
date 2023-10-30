#include <iostream>
#include <cstdlib>
#include <type_traits>
#include <vector>
/*
 * The class describes how to construct a tree
 * The definition of each node is given and associated operations are coded.
 * We use template programming here to make the tree generalize for different
 * datatypes.
 */

/* Tree node of type int
 */
class TreeNode
{
public:
    int data;
    std::vector<TreeNode*> child_node_ptrs;
    TreeNode(const int data, const int number_of_children){
        this->data = data;
        this->child_node_ptrs = std::vector<TreeNode*>(number_of_children);
    }
};
