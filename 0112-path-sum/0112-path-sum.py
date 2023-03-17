# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, root: Optional[TreeNode], total: int, targetSum: int) -> bool:
        if not root:
            return False
        
        if not root.left and not root.right:
            return total + root.val == targetSum
            
        left = self.dfs(root.left, total + root.val, targetSum)
        right = self.dfs(root.right, total + root.val, targetSum)
        
        return left or right
    
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        if not root:
            return False
        return self.dfs(root, 0, targetSum)