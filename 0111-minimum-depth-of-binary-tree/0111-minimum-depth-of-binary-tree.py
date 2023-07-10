# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, node: Optional[TreeNode], height: int) -> int:
        if not node.left and not node.right:
            return height
        ans = float('inf')
        if node.left:
            ans = min(ans, self.dfs(node.left, height + 1))
        if node.right:
            ans = min(ans, self.dfs(node.right, height + 1))
        return ans
    
    def minDepth(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        
        return self.dfs(root, 1)