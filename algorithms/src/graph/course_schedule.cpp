#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool dfs(int node, vector<vector<int>> &adj, vector<bool>& visit, vector<bool>& instack){
        if (instack[node]){
            return true;
        }

        if(visit[node]){
            return false;
        }
        visit[node] = true;
        instack[node] = true;
        for (auto neighbor: adj[node]){
            if (dfs(neighbor, adj, visit, instack)){
                return true;
            }
        }
        instack[node] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites){
        vector<vector<int>> adj(numCourses);
        for (auto prerequisite: prerequisites){
            adj[prerequisite[1]].push_back(prerequisite[0]);
        }

        vector<bool> visit(numCourses);
        vector<bool> instack(numCourses);
        for (int i = 0; i < numCourses; i++){
            if (dfs(i , adj, visit, instack)){
                return false;
            }
        }
        return true;


    }
    bool canFinish1(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses);
        vector<vector<int>> adj(numCourses);
        // create graph
        for(auto prerequisite: prerequisites){
                adj[prerequisite[1]].push_back(prerequisite[0]);
                indegree[prerequisite[0]]++;
            }

        queue<int> q;

        for(int i = 0; i < numCourses; i++){
            if (indegree[i] == 0){
                q.push(i);
            }
        }

        int nodesVisited = 0;
        // breadth first search on nodes with zero indegree.
        while (!q.empty()){
            int node = q.front();
            q.pop();
            nodesVisited++;
            for (auto& neighbour : adj[node]){
                indegree[neighbour] --;
                if(indegree[neighbour] == 0){
                    q.push(neighbour);
                }
            }
        }
        return nodesVisited == numCourses;

    }
};
