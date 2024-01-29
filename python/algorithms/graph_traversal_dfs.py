'''
Graph is different from a tree as each node can be visited
more than once. So a graph can have more than DFS traversal.

# program to print DFS traversal from a given graph
@author Jagatpreet Singh Nir

'''

from collections import defaultdict


class Graph:

    def __init__(self):
        self.graph = defaultdict(list)

    def addEdge(self, u, v):
        self.graph[u].append(v)

    def DFSUtil(self, v, visited):

        # Mark the current node as visited
        visited.add(v)
        print(v, end=",")

        for neighbour in self.graph[v]:
            # Recurse
            if neighbour not in visited:
                self.DFSUtil(neighbour, visited)

    def DFS(self, v):

        visited = set()
        self.DFSUtil(v, visited)


if __name__ == "__main__":
    g = Graph()
    g.addEdge(0, 1)
    g.addEdge(0, 2)
    g.addEdge(1, 2)
    g.addEdge(2, 0)
    g.addEdge(2, 3)
    g.addEdge(3, 3)

    print("Depth first traveral from vertex 2:")
    g.DFS(2)
    print("\n")
