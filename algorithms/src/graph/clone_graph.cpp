#include <iostream>
#include <map>
#include <vector>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    void dfs(Node* root, map<int, Node*> &visited_nodes){
        Node* n;
        if (visited_nodes.find(root->val) != visited_nodes.end()){
            // create new node
            return;
        }

        n = new Node();

        n->val = root->val;
        visited_nodes[n->val] = n;
        cout << " node value = " << n->val;
        for (auto nbr: root->neighbors){
            // first create and store the subgraph
            dfs(nbr, visited_nodes);
            // save the neibours of current node after creating them.
            n->neighbors.push_back(visited_nodes[nbr->val]);

        }

    }

    Node* cloneGraph(Node* node) {
        if (node==NULL){
            return nullptr;
        }
        if(node->neighbors.size() == 0){
            Node *n = new Node(node->val);
            return n;
        }
        map<int, Node*> nodes;
        dfs(node, nodes);
        return nodes[node->val];
    }
};
