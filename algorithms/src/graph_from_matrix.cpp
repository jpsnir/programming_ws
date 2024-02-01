#include <iostream>
#include <list>
#include <map>
#include <tuple>
#include <vector>
using namespace std;

int main() {
  vector<vector<int>> matrix = {
      {1, 2, 3},
      {4, 5, 6},
      {7, 8, 9},
  };

  // store adjacency list of graph
  vector<list<int>> adj;
  vector<list<pair<int, int>>> adj_pair;
  adj.resize(3);
  adj_pair.resize(9);

  std::map<int, pair<int, int>> node_map;
  map<pair<int, int>, int> inverse_node_map;
  int node_id = 0;
  // store all nodes in map
  // for each node store the connections
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[0].size(); j++) {
      node_map[node_id] = {i, j};
      inverse_node_map[pair<int, int>(i, j)] = node_id;

      cout << node_id << ": (" << i << "," << j << ")"
           << "added" << endl;
      // handling corners
      if (i == 0 && j == 0) {
        adj_pair[node_id].push_back(pair<int, int>(i + 1, j));
        adj_pair[node_id].push_back(pair<int, int>(i, j + 1));
      node_id++;
        continue;
      }

      if (i == 0 && j == matrix.size() - 1) {
        adj_pair[node_id].push_back(pair<int, int>(i + 1, j));
        adj_pair[node_id].push_back(pair<int, int>(i, j - 1));
      node_id++;
        continue;
      }

      if (i == matrix.size() - 1 && j == 0) {
        adj_pair[node_id].push_back(pair<int, int>(i - 1, j));
        adj_pair[node_id].push_back(pair<int, int>(i, j + 1));
      node_id++;
        continue;
      }

      if (i == matrix.size() - 1 && j == matrix.size() - 1) {
        adj_pair[node_id].push_back(pair<int, int>(i - 1, j));
        adj_pair[node_id].push_back(pair<int, int>(i, j - 1));
      node_id++;
        continue;
      }

      // handle boundaries
      if (i == 0) {
        adj_pair[node_id].push_back(pair<int, int>(i + 1, j));
        adj_pair[node_id].push_back(pair<int, int>(i, j- 1));
        adj_pair[node_id].push_back(pair<int, int>(i, j + 1));
      node_id++;
        continue;
      }
      if (j == 0) {
        adj_pair[node_id].push_back(pair<int, int>(i + 1, j));
        adj_pair[node_id].push_back(pair<int, int>(i-1, j));
        adj_pair[node_id].push_back(pair<int, int>(i, j + 1));
      node_id++;
        continue;
      }

      if (i == matrix.size() - 1) {
        adj_pair[node_id].push_back(pair<int, int>(i - 1, j));
        adj_pair[node_id].push_back(pair<int, int>(i, j + 1));
        adj_pair[node_id].push_back(pair<int, int>(i, j - 1));
      node_id++;
        continue;
      }
      if (j == matrix.size() - 1) {
        adj_pair[node_id].push_back(pair<int, int>(i + 1, j));
        adj_pair[node_id].push_back(pair<int, int>(i - 1, j));
        adj_pair[node_id].push_back(pair<int, int>(i, j - 1));
      node_id++;
        continue;
      }
      adj_pair[node_id].push_back(pair<int, int>(i + 1, j));
      adj_pair[node_id].push_back(pair<int, int>(i - 1, j));
      adj_pair[node_id].push_back(pair<int, int>(i, j + 1));
      adj_pair[node_id].push_back(pair<int, int>(i, j - 1));
      node_id++;
      cout << " internal elements added " << endl;
    }
  }
  cout << " Node map size = " << adj_pair.size() << ":" << node_map.size() << endl;
  for (int i = 0; i < adj_pair.size(); i++) {
    pair<int, int> node = node_map[i];
    cout << " cell (" << node.first << "," << node.second << ") :  ";
    for (auto connected : adj_pair[i]) {
      cout << " ,(" << connected.first << "," << connected.second << ")  ";
    }
    cout << endl;
  }
}
