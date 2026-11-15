# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        ancestor, st = dict(), [(None, root)]

        while st:
            parent, child = st.pop()
            ancestor[child] = parent

            if child.left:
                st.append((child, child.left))

            if child.right:
                st.append((child, child.right))

        if not (p in ancestor and q in ancestor):
            return None

        while p:
            q_cp = q
            while q_cp:
                if p and q_cp and p.val == q_cp.val:
                    return p
                q_cp = ancestor[q_cp]

            p = ancestor[p]

        return None