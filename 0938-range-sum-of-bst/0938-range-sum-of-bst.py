# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rangeSumBST(self, root: Optional[TreeNode], low: int, high: int) -> int:
        total = 0
        queue = deque([root])
        
        while queue:
            q = queue.popleft()
            if low <= q.val <= high:
                total += q.val
            
            if q.left:
                queue.append(q.left)
            
            if q.right:
                queue.append(q.right)
        
        return total
        
        