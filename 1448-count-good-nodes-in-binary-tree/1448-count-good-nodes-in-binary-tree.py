# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, node: TreeNode, max_so_far: int) -> int:
        if not node: return 0
        
        left = self.dfs(node.left, max(max_so_far, node.val))
        
        right = self.dfs(node.right, max(max_so_far, node.val))
        
        ans = left + right
        if node.val >= max_so_far:
            ans += 1
        
        return ans
    
    def goodNodes(self, root: TreeNode) -> int:
        return self.dfs(root, float('-inf'))