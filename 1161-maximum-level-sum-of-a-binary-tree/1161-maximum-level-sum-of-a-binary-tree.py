# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, node: Optional[TreeNode], level: int, sum_at_current_level: List) -> None:
        if not node:
            return
        
        if len(sum_at_current_level) == level:
            sum_at_current_level.append(node.val)
        else:
            sum_at_current_level[level] += node.val
            
        self.dfs(node.left, level + 1, sum_at_current_level)
        self.dfs(node.right, level + 1, sum_at_current_level)
    
    def maxLevelSum(self, root: Optional[TreeNode]) -> int:
        sum_at_current_level = []
        self.dfs(root, 0, sum_at_current_level)
        return 1 + sum_at_current_level.index(max(sum_at_current_level))