# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    
    def minDepth(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        stack, ans = [(root, 1)], float('inf')
        
        while stack:
            node, height = stack.pop()
            if not node.left and not node.right:
                ans = min(ans, height)
            
            if node.left:
                stack.append((node.left, height + 1))
            
            if node.right:
                stack.append((node.right, height + 1))
        
        return ans