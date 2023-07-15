# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def dfs(self, node: 'TreeNode', target: 'TreeNode') -> bool:
        if node == target:
            return True
        if not node:
            return False
        return self.dfs(node.left, target) or self.dfs(node.right, target)
    
    def LCA(self, node: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if not node or node == p or node == q:
            return node
        
        left = self.LCA(node.left, p, q)
        right = self.LCA(node.right, p, q)
        if left and right:
            return node
        elif left:
            return left
        return right
    
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        ans = self.LCA(root, p, q)
        
        if ans == p:
            return p if self.dfs(p, q) else None
        elif ans == q:
            return q if self.dfs(q, p) else None
        return ans