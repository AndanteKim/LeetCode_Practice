# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    minDistance = 2**31
    prevValue = None
    
    def dfs(self, root: Optional[TreeNode]) -> None:
        if not root: return
        
        self.dfs(root.left)
        
        if self.prevValue:
            self.minDistance = min(self.minDistance, root.val - self.prevValue.val)
        self.prevValue = root

        self.dfs(root.right)
    
    def minDiffInBST(self, root: Optional[TreeNode]) -> int:
        self.dfs(root)
        
        return self.minDistance