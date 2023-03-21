# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    diameter = 0
    def longest_path(self, node: Optional[TreeNode]) -> int:
        if not node:
            return 0
        
        left_path = self.longest_path(node.left)
        right_path = self.longest_path(node.right)
        self.diameter = max(self.diameter, left_path + right_path)
        
        return max(left_path, right_path) + 1
    
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        self.longest_path(root)
        
        return self.diameter