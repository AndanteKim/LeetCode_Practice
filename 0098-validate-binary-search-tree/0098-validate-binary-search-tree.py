# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, node: Optional[TreeNode], small: int, large: int) -> bool:
        if not node:
            return True
        
        if not (small < node.val < large):
            return False
        
        left = self.dfs(node.left, small, node.val)
        right = self.dfs(node.right, node.val, large)
        
        return left and right
    
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        
        return self.dfs(root, float('-inf'), float('inf'))