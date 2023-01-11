# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if not root: return 0
        depth, queue = 0, deque([(1, root)])
        
        while queue:
            depth, q = queue.popleft()
            
            if q and q.left:
                queue.append((depth+1, q.left))
            
            if q and q.right:
                queue.append((depth+1, q.right))
            
            
        return depth