import matplotlib.pyplot as plt
import networkx as nx
from matplotlib.animation import FuncAnimation
import numpy as np

# Create a graph
G = nx.Graph()
ones = np.ones(10)
adj_matrix = np.diag(np.ones(10), k=1) + np.diag(np.ones(9), k=2) + np.diag(np.ones(8), k=3)

breakpoint()

# Add some nodes
G.add_nodes_from(range(10))

# Create an empty plot
fig, ax = plt.subplots()

# Function to update the graph with new edges


def edges(adj_matrix):
    M, N = adj_matrix.shape
    for i in range(1, M):
        temp = adj_matrix[:i, :i]
        temp_new = adj_matrix[:i + 1, :i + 1]
        m = np.zeros([i + 1, i + 1])
        m[:i, :i] = temp
        rows, cols = np.where(temp_new - m == 1)
        edges = zip(rows.tolist(), cols.tolist())
        yield edges


def update(edges):
    G.add_edges_from(edges)
    # Draw the updated graph
    ax.clear()
    pos = nx.circular_layout(G)
    nx.draw(G, pos, ax=ax, with_labels=True)
    ax.set_title('Frame')


# Create the animation
ani = FuncAnimation(fig, update, frames=edges(adj_matrix), interval=1000, repeat=False)

# Display the animation
plt.show()
