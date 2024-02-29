# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def equalToDescendants(self, root: Optional[TreeNode]) -> int:
        def dfs(node: Optional[TreeNode]) -> int:
            if not node:
                return 0
            
            nonlocal count
            left = dfs(node.left)
            right = dfs(node.right)
            
            if node.val == left + right:
                count += 1
                
            return left + right + node.val
        
        
        count = 0
        dfs(root)
        return count