# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findBottomLeftValue(self, root: Optional[TreeNode]) -> int:
        queue, current = deque([root]), root
        
        while queue:
            current = queue.popleft()
            
            if current.right:
                queue.append(current.right)
            
            if current.left:
                queue.append(current.left)
                
        return current.val