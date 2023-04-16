# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        
        if not p and not q:
            return True
        if (p and not q) or (not p and q):
            return False
        
        queue = deque([(p, q)])
        
        while queue:
            p_derive, q_derive = queue.popleft()
            if p_derive.val != q_derive.val:
                return False
            
            if p_derive.left and q_derive.left:
                queue.append((p_derive.left, q_derive.left))
            elif (not p_derive.left and q_derive.left) or (p_derive.left and not q_derive.left):
                return False
            
            if p_derive.right and q_derive.right:
                queue.append((p_derive.right, q_derive.right))
            elif (not p_derive.right and q_derive.right) or (p_derive.right and not q_derive.right):
                return False
            
        return True