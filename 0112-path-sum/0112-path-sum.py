# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        if not root:
            return False
        
        queue = deque([(root, 0)])
        
        while queue:
            q, total = queue.popleft()
            if not q.left and not q.right:
                if total + q.val == targetSum:
                    return True
            if q.left:
                queue.append((q.left, total + q.val))
            
            if q.right:
                queue.append((q.right, total + q.val))
                
        return False