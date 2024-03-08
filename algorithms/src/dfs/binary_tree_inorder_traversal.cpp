#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  void inorder(TreeNode *root, vector<int> &v) {
    if (root == nullptr)
      return;
    inorder(root->left, v);
    v.push_back(root->val);
    inorder(root->right, v);
  };
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> v;
    inorder(root, v);
    return v;
  };
  void inorder_stack(TreeNode* root, vector<int> &v){
        stack<TreeNode*> st;
        TreeNode* root1 = root;

        // left stack
        while(root1!=nullptr || !st.empty()){
            while(root1 != nullptr){
                st.push(root1);
                root1 = root1->left;
            }
            TreeNode* n = st.top();
            st.pop();
            cout << n->val << "," ;
            v.push_back(n->val);
            root1 = n->right;
        }
        cout << endl;
    }
  void morris_traversal(TreeNode* root, vector<int> &v){
        TreeNode* curr = root;
        while(curr != nullptr){
            if(curr->left == nullptr){
                v.push_back(curr->val);
                curr = curr->right;
            }
            else{
                TreeNode* t = curr->left;
                while(t->right != nullptr){
                    t = t->right;
                }
                t->right = curr;
                TreeNode* temp = curr;
                curr = curr->left;
                temp->left = nullptr;
            }
        }
    }
};
