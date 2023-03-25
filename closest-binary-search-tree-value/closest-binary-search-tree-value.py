# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def closestValue(self, root: Optional[TreeNode], target: float) -> int:
        stack, ans = [root], float('inf')
        
        while stack:
            node = stack.pop()
            if abs(node.val - target) <= abs(ans - target):
                ans = node.val
                
            if node.left:
                stack.append(node.left)
            if node.right:
                stack.append(node.right)
                
        return ans
            
            