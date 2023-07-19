'''
Depth first search with a tree data structure.

There are multiple ways to traverse a tree.
1. Depth first search
    a. Inorder Traversal
    b. Preorder Traversal
    c. Postorder Traversal
2. Level Order Traversal or Bread First Search
3. Boundary Traveral
4. Diagonal Traveral.
'''


class Node:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.val = key


def print_in_order(root):

    if root:

        print_in_order(root.left)
        print(root.val, end=",")
        print_in_order(root.right)


def print_pre_order(root):
    '''
    can be used to get prefix expression of an expression tree.

    '''
    if root:
        print(root.val, end=",")
        print_pre_order(root.left)
        print_pre_order(root.right)


def print_post_order(root):
    '''
    can be used to delete a tree - leaves first
    and also to get post-fix expression.
    '''
    if root:
        print_post_order(root.left)
        print_post_order(root.right)
        print(root.val, end=",")


if __name__ == "__main__":
    root = Node(1)
    root.left = Node(2)
    root.right = Node(3)
    root.left.left = Node(4)
    root.left.right = Node(5)
    root.right.left = Node(6)
    root.right.right = Node(7)

    print("Inorder Traversal of binary tree is")
    print_in_order(root)
    print("\n Pre-order Traversal of binary tree is")
    print_pre_order(root)
    print("\n Post-order Traversal of binary tree is")
    print_post_order(root)
    print("\n")
