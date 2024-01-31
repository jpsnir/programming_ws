#include <iostream>
#include <vector>
#include<list>

using namespace std;

class Graph {
    // number of nodes
    int n;
    // adjacency list can store the graph completely
    vector<list<int>> adj;

    public:

        Graph(int v);
        // add edge between two vertices
        void addEdge(int v, int w);
        // bread first search from a given source
        void bread_first_search(int s);
};

Graph::Graph(int n){
    this->n = n;
    adj.resize(n);
}

void Graph::addEdge(int v, int w){

    // node v is connected to w
    adj[v].push_back(w);
}

void Graph::bread_first_search(int s){
    vector<bool> visited;
    visited.resize(n, false);
    // queue that saves the nearest nodes.
    list<int> queue;

    // add root node
    queue.push_back(s);
    visited[s] = true;
    // work until the queue is empty for BFS
    while(! queue.empty()){
        s = queue.front();
        cout << s << "," ;
        queue.pop_front();

        //get all connected nodes to s
        for (auto connected : adj[s]){
            if (!visited[connected]){
                visited[connected] = true;
                queue.push_back(connected);
            }
        }
    }
    cout << endl;
}

int main(){
    // create graph
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    cout << " start from node 3 \n";
    g.bread_first_search(3);

    cout << "\n start from node 1 \n";
    g.bread_first_search(1);

    cout << "\n start from node 2 \n" ;
    g.bread_first_search(2);


}
