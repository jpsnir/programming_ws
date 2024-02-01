#include <iostream>
#include <list>
#include <queue>
#include <vector>

using namespace std;

class Graph {
public:
  int n;
  vector<list<int>> adj;
  vector<list<float>> weights;
  Graph(int n) {
    this->n = n;
    adj.resize(n);
    weights.resize(n);
  }
  void add_edge(int v, int e, float w) {
    adj[v].push_back(e);
    weights[v].push_back(w);
  }

  void bfs_print(int s) {
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while (!q.empty()) {
      int node = q.front();
      q.pop();
      cout << node << ",";
      // for each level push the elements
      for (auto connected : adj[node]) {
        if (!visited[connected]) {
          q.push(connected);
        }
        visited[connected] = true;
      }
      // level complete.
    }
  }

  int bfs_search(int start_node, int search_node) {
        vector<bool> visited(n, false);
        queue<int> q;
        vector<int> l;
        q.push(start_node);
        int level = 0;
        vector<int> node_at_each_level;
        int count;
        visited[start_node] = true;
        bool not_found = true;
        while (!q.empty() || not_found) {
            int sz = q.size();
            cout << "current level = " << level << endl;
            // empty the complete level
            while (sz--) {
              int node = q.front();
              q.pop();
              if (node == search_node) {
                cout << " search node found " << node << endl;
                not_found = false;
                goto loop_exit;
              }
              count++;
              //cout << node << ",";
              l.push_back(adj.size());
              // for each level push the elements
              for (auto connected : adj[node]) {
                if (!visited[connected]) {
                  q.push(connected);
                }
                visited[connected] = true;
              }
            }
            level++;
            // level complete.
        }
    loop_exit:
        if (not_found)
            return -1;
        else
            return level;
  }
};

int main(){
    Graph g(5);
    g.add_edge(0, 1, 0.1);
    g.add_edge(0, 2, 0.1);
    g.add_edge(1, 3, 0.1);
    g.add_edge(2, 4, 0.1);
    g.bfs_print(0);
    int level = g.bfs_search(0, 3);

    // Function call
    cout << "level = " << level << endl;
}
