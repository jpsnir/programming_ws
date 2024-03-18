#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void dfs(int i, vector<vector<int>> &adj, vector<bool> &visited){

        for (auto nbr : adj[i]){
            // this will prevent cycles
            if (!visited[nbr]){
                visited[nbr] = true;
                dfs(nbr, adj, visited);
            }

        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto e : edges){
            adj[e[1]].push_back(e[0]);
            adj[e[0]].push_back(e[1]);
        }

        vector<bool> visited(n);
        int components = 0;
        for(int i = 0; i < adj.size(); i++){
            if (!visited[i]){
                visited[i] = true;
                // visit all connections
                dfs(i, adj, visited);
                components ++;
            }

        }
        return components;
    }
};
