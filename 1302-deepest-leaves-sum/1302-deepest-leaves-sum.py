# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    
    ans, depth = 0, 0
    def dfs(self, node: Optional[TreeNode], level: int) -> None:
        if not node:
            return
        
        if level == self.depth:
            self.ans += node.val
        
        elif level > self.depth:
            self.ans = node.val
            self.depth = level
        
        self.dfs(node.left, level + 1)
        self.dfs(node.right, level + 1)
    
    def deepestLeavesSum(self, root: Optional[TreeNode]) -> int:
        self.dfs(root, 0)
        return self.ans