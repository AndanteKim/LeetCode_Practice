# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rob(self, root: Optional[TreeNode]) -> int:
        
        @lru_cache(maxsize = None)
        def dfs(node: Optional[TreeNode], stolen: bool):
            if not node:
                return 0
            
            curr = 0
            if stolen:
                curr = dfs(node.left, False) + dfs(node.right, False)
            else:
                curr = max(node.val + dfs(node.left, True) + dfs(node.right, True), dfs(node.left, False) + dfs(node.right, False))
            
            return curr
            
            
            
        return dfs(root, False)
        