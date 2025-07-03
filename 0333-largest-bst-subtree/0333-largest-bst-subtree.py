# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class NodeValue:
    def __init__(self, min_node: int, max_node: int, max_size: int):
        self.max_node = max_node
        self.min_node = min_node
        self.max_size = max_size

class Solution:
    def helper(self, node: Optional[TreeNode]) -> 'NodeValue':
        # An empty tree is a BST of size 0
        if not node:
            return NodeValue(float('inf'), float('-inf'), 0)

        # Get values from left and right subtrees of current tree.
        left = self.helper(node.left)
        right = self.helper(node.right)

        # Current node is greater than max in left and smaller than in right, it's a BST.
        if left.max_node < node.val < right.min_node:
            # It's a BST.
            return NodeValue(min(node.val, left.min_node), max(node.val, right.max_node), left.max_size + right.max_size + 1)

        # Otherwise, return [-inf, inf], so that parent can't be a valid BST
        return NodeValue(float('-inf'), float('inf'), max(left.max_size, right.max_size))

    def largestBSTSubtree(self, root: Optional[TreeNode]) -> int:
        return self.helper(root).max_size

        