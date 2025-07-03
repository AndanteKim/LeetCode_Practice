# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def is_valid_bst(self, root: Optional[TreeNode]) -> bool:
        """
        Check if given tree is a valid BST using in-order traversal.
        """
        # An empty tree is a valid Binary Search Tree.
        if not root:
            return True
        
        # If left subtree isn't a valid BST return false.
        if not self.is_valid_bst(root.left):
            return False

        # If current node's value isn't greater than the previous
        # node's value in the in-order traversal return false.
        if self.prev and self.prev.val >= root.val:
            return False
        
        # Update previous node to current node.
        self.prev = root

        # If right subtree isn't a valid BST return False
        return self.is_valid_bst(root.right)

    # Count nodes in current tree.
    def count_nodes(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0

        # Add nodes in left and right subtree.
        # Add 1 and return total size.
        return 1 + self.count_nodes(root.left) + self.count_nodes(root.right)
        
    def largestBSTSubtree(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0

        # Previous node is initially null.
        self.prev = None

        # If current subtree is a valid BST, its children will have smaller size BST.
        if self.is_valid_bst(root):
            return self.count_nodes(root)
        
        # Find BST in left and right subtrees of current nodes.
        return max(self.largestBSTSubtree(root.left), self.largestBSTSubtree(root.right))