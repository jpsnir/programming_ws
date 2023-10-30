#include <iostream>
#include <cstdlib>
#include <math.h>
#include <type_traits>
#include <vector>
#include <string>
#include <ostream>
#include <sstream>
#include <cassert>

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
        this->child_node_ptrs = std::vector<TreeNode*>(number_of_children,nullptr);
    }
    void assign_children(const std::vector<TreeNode*> nodes){
        assert(nodes.size() == child_node_ptrs.size());
        for (int i = 0; i < child_node_ptrs.size(); i++)
            child_node_ptrs[i] = nodes[i];
    }
    void list_all_children(){
        for (int i=0; i < this->child_node_ptrs.size(); i++){
            std::stringstream val;
            if (child_node_ptrs[i] == nullptr)
                val <<  "null";
            else
                val << child_node_ptrs[i]->data;
            std::string output;
            val >> output;
            std::cout << "child = " << i << " - " << output << std::endl;
        }
    }
};


// binary tree has 2 child nodes, so each treeNode(data, 2)
// Ternary tree has 3 child nodes, so each treeNode is defined by (data, 3)
//
//
//
int main(){
    TreeNode* root= new TreeNode(10, 2);
    std::cout << " Before assigning childre " << std::endl;
    root->list_all_children();
    std::vector<TreeNode*> ch_node_ptrs(2);
    ch_node_ptrs[0] = new TreeNode(10,2);
    ch_node_ptrs[1] = new TreeNode(10,2);
    std::cout << " After assigning childre " << std::endl;
    root->assign_children(ch_node_ptrs);
    root->list_all_children();
}
