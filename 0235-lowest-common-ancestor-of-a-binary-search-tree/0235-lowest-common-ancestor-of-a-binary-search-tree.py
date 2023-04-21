# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        ancestors = dict()
        
        queue = deque([(root, None)])
        
        while queue:
            child, parent = queue.popleft()
            ancestors[child] = parent
            
            if child.left:
                queue.append((child.left, child))
            
            if child.right:
                queue.append((child.right, child))
        
        seen = set()
        while p:
            seen.add(p)
            p = ancestors[p]
            
        while q not in seen:
            q = ancestors[q]
        
        return q