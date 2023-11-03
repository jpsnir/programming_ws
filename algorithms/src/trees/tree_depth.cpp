#include <iostream>
#include <vector>
#include <cassert>
#include <queue>

class TreeNode{
public:
    int data;
    std::vector<TreeNode*> children;
    TreeNode(int data, size_t n){
        this-> data = data;
        if (n>0)
            children = std::vector<TreeNode*>(n);

    }
    void insert_children(const std::vector<TreeNode*> &nodes){
        assert(!children.empty() && nodes.size() == children.size());
        for (int i = 0; i < nodes.size(); i++){
            children[i] = nodes[i];
        }
    }

};

void view_tree(const TreeNode* root, std::queue<int> &q){
    //level order traversal
    q.push(root->data);
    if (root->children.empty()){
        return;
    }

    std::cout << root->data << std::endl;
    for (auto child_ptr:root->children){
        std::cout << child_ptr->data << "," <<  std::endl;
        view_tree(child_ptr, q);
    }
}

void tree_depth(const TreeNode* root, int &depth){
    if (root->children.empty()){
        depth += 1;
        return;
    }
    int child_depth = 0;
    for(auto child_ptr: root->children){
        tree_depth(child_ptr, child_depth);
        if (depth > child_depth)
            depth = child_depth;
    }
}

int main(){
    auto root = new TreeNode(0, 2);
    auto l_level1 = new TreeNode(1, 1);
    auto l_level2 = new TreeNode(3, 0);
    auto r_level1 = new TreeNode(2, 2);
    std::vector<TreeNode*> vec_1 = {l_level1, r_level1};
    root->insert_children(vec_1);
    std::vector<TreeNode*> vec_2 = {l_level2};

    l_level1->children[0]->insert_children(vec_2);
    int max_depth = 0;
    tree_depth(root, max_depth);
    std::cout << " The max depth of the tree is = " << max_depth + 1<< std::endl;
}
