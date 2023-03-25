# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def closestValue(self, root: Optional[TreeNode], target: float) -> int:
        queue, ans = deque([root]), float('inf')
        
        while queue:
            node = queue.popleft()
            if abs(node.val - target) <= abs(ans - target):
                ans = node.val
                
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)
                
        return ans
            
            