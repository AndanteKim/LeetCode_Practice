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
        
        p_ancestor = p
        while p_ancestor:
            q_ancestor = q
            while q_ancestor:
                if p_ancestor == q_ancestor:
                    return p_ancestor
                q_ancestor = ancestors[q_ancestor]
            p_ancestor = ancestors[p_ancestor]
        return None
        