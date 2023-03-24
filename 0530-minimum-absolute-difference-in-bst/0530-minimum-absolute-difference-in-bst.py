# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, root: Optional[TreeNode]) -> None:
        if not root:
            return
        self.dfs(root.left)
        self.flatten.append(root.val)
        self.dfs(root.right)
    
    def getMinimumDifference(self, root: Optional[TreeNode]) -> int:
        self.flatten = []
        self.dfs(root)
        ans = float('inf')
        
        for i in range(len(self.flatten) - 1):
            ans = min(ans, self.flatten[i+1] - self.flatten[i])
        
        return ans