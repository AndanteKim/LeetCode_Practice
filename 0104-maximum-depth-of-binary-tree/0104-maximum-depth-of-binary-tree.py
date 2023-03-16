# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        return max(1 + self.dfs(root.left), 1 + self.dfs(root.right))
    
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        return self.dfs(root)