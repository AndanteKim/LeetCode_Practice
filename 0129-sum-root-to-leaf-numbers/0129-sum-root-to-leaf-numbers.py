# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, root: Optional[TreeNode], total: int) -> int:
        if not root:
            return 0
        
        total = total * 10 + root.val
        if not root.left and not root.right:
            return total
        
        return self.dfs(root.left, total) + self.dfs(root.right, total)
    
    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        return self.dfs(root, 0)