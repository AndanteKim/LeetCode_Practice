# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumOfLeftLeaves(self, root: Optional[TreeNode]) -> int:
        if not root.left and not root.right: return 0
        tot, queue = 0, deque([root])
        
        while queue:
            q = queue.popleft()
            
            if q.left:
                if not (q.left.left or q.left.right):
                    print(q.left.val)
                    tot += q.left.val
                queue.append(q.left)
                
            if q.right:
                queue.append(q.right)
        
        return tot
            