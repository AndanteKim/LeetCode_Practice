# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    nodes_found = False
    def dfs(self, node: 'TreeNode', p, q) -> 'TreeNode':
        if not node:
            return node
        
        left, right = self.dfs(node.left, p, q), self.dfs(node.right, p, q)
        conditions = 0
        if node in (p, q):
            conditions += 1
        if left:
            conditions += 1
        if right:
            conditions += 1
        if conditions == 2:
            self.nodes_found = True
        
        if (left and right) or node in (p, q):
            return node
        return left or right
    
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        ans = self.dfs(root, p, q)
        return ans if self.nodes_found else None