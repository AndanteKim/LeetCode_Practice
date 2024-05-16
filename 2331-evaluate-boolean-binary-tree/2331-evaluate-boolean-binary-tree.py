# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def evaluateTree(self, root: Optional[TreeNode]) -> bool:
        def dfs(curr: Optional[TreeNode]) -> bool:
            # If it's leaf node
            if not (curr.left and curr.right):
                return True if curr.val else False
            
            return dfs(curr.left) | dfs(curr.right) if curr.val == 2 else dfs(curr.left) & dfs(curr.right)
            
        return dfs(root)