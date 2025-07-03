# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def is_valid_bst(self, root: Optional[TreeNode]) -> bool:
        """
        Check if given tree is a valid Binary Search Tree.
        """
        if not root:
            return True
        
        # Find the max node in the left subtree of current node.
        left_max = self.find_max(root.left)

        # If the left subtrees has a node greater than or equal to the current node.
        # then it's not a valid Binary Search Tree.
        if left_max >= root.val:
            return False
        
        # Find the min node in the right subtree of current node.
        right_min = self.find_min(root.right)
        if right_min <= root.val:
            return False

        # If the left and right subtrees of current tree are also valid BST,
        # then the whole tree is a BST.
        return self.is_valid_bst(root.left) and self.is_valid_bst(root.right)

    def find_max(self, root: Optional[TreeNode]) -> int:
        # Max node in a empty tree should be smaller than parent.
        if not root:
            return float('-inf')

        # Check the maximum node from the current node, left and right subtree of the current tree.
        return max(root.val, self.find_max(root.left), self.find_max(root.right))

    def find_min(self, root: Optional[TreeNode]) -> int:
        # Min node in a empty tree should be larger than parent.
        if not root:
            return float('inf')
        
        # Check the minimum node from the current node, left and right subtree of the current tree
        return min(root.val, self.find_min(root.left), self.find_min(root.right))

    def count_nodes(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0

        # Add nodes in left and right subtree.
        # Add 1 and return total size.
        return 1 + self.count_nodes(root.left) + self.count_nodes(root.right)

    def largestBSTSubtree(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        
        # If current subtree is a valid BST, its children will have smaller size BST.
        if self.is_valid_bst(root):
            return self.count_nodes(root)
        
        # Find BST in left and right subtrees of current nodes.
        return max(self.largestBSTSubtree(root.left), self.largestBSTSubtree(root.right))