# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        parents = dict()
        queue = deque([(None, root)])

        while queue:
            parent, child = queue.popleft()

            parents[child] = parent

            if child.left:
                queue.append((child, child.left))

            if child.right:
                queue.append((child, child.right))

        # Base case
        if not (p in parents and q in parents):
            return None
        
        ancestor_p = p
        while ancestor_p in parents:
            ancestor_q = q
            while ancestor_q in parents:
                if ancestor_p == ancestor_q:
                    return ancestor_p
                ancestor_q = parents[ancestor_q]
            ancestor_p = parents[ancestor_p]
        
        return None