# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        
        total, queue = 0, deque([(root, root.val)])
        
        while queue:
            q, prev_max_val = queue.popleft()
            
            if q.val >= prev_max_val:
                total += 1
            
            if q.left:
                queue.append((q.left, max(q.val, prev_max_val)))
            
            if q.right:
                queue.append((q.right, max(q.val, prev_max_val)))
                
        return total