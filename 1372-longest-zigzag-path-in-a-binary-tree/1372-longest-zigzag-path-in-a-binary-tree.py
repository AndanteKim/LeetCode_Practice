# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, node: Optional[TreeNode], goLeft: bool, steps: int) -> None:
        if node:
            self.ans = max(self.ans, steps)
            
            if goLeft:
                self.dfs(node.left, False, steps + 1)
                self.dfs(node.right, True, 1)
            else:
                self.dfs(node.left, False, 1)
                self.dfs(node.right, True, steps + 1)
    
    def longestZigZag(self, root: Optional[TreeNode]) -> int:
        self.ans = 0
        
        self.dfs(root, False, 0)
        self.dfs(root, True, 0)
        
        return self.ans