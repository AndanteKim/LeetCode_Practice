# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxAncestorDiff(self, root: Optional[TreeNode]) -> int:
        stack = [(root, float('-inf'), float('inf'), float('-inf'))]
        ans = 0
        while stack:
            node, mx, mn, max_diff = stack.pop()
            mx, mn = max(mx, node.val), min(mn, node.val)
            max_diff = max(abs(mx - mn), max_diff)
            ans = max(ans, max_diff)
            
            if node.left:
                stack.append((node.left, mx, mn, max_diff))
            
            if node.right:
                stack.append((node.right, mx, mn, max_diff))
            
        return ans