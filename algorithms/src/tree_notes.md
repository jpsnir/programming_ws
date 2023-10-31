# Concepts
1. Depth of node: Edges from root to the node.
2. Height of node: Edges from node to the leaf.
3. Height of tree: No. of edges from root node to lowest leaf node.
4. Degree of Tree: Degree of node is total count of sub-trees. Degree of tree is
   the highest number from all nodes in tree.

- represents hierarchy data, non linear storage.
- Trees with some ordering (BST) provides moderate access/search and better
    insertion than array but not as good as list : quicker
than linked list and slower than arrays
    access in an array : O(1)
    search in an array : O(n)
    insertion in an array: O(n)

    access in list : O(n)
    search in list : O(n)
    insertion in list : O(1)

    access in BST: O(log n)
    search in BST: O(log n)
    insertion in BST: O(log n)

- Applications
    - Hierarchy of data: filesystem
    - Data compression: Huffman coding
    - compiler design : syntax tree, expression tree.
    -
