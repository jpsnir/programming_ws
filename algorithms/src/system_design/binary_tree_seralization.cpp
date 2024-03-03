#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode (int x): val(x), left(nullptr), right(nullptr) {};
};


class Codec{
    public:
        Codec(char delimiter = ','){
        }

        string serialize(TreeNode* root){
            ss << "i"<<",";
            inorder(root);
            ss << "p" << ",";
            preorder(root);
            return ss.str();
        }

        TreeNode* deserialize(string data){
            int inorder_start = 0;
            int preorder_start = data.find_first_of("c");
            string inorder_string = data.substr(0, preorder_start - 1);
            string preorder_string = data.substr(preorder_start, data.size() - 1);
            auto v_inorder = parse_tree_string(inorder_string);
            auto v_preorder = parse_tree_string(preorder_string);
            return construct_tree(v_inorder, v_preorder);
        }
    private:
        // TODO: can use an array the size of number of elements is known and
        // can be passed in the end of string
        vector<int> parse_tree_string(string s){};
        TreeNode* construct_tree(vector<int> inorder, vector<int> preorder){
        }
        void inorder(TreeNode *root){
            if (root == NULL)
                return;
            ss << root->val << ",";
            inorder(root->left);
            preorder(root->right);
        };
        void preorder(TreeNode* root){
            if (root == NULL)
                return;
            preorder(root->left);
            ss << root->val<< ",";
            preorder(root->right);
        };
        stringstream ss;
};
