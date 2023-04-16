# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, root: Optional[TreeNode]) -> List[int]:
        stack = [root]
        r_leaves = []
        
        while stack:
            r = stack.pop()
            if not r.left and not r.right:
                r_leaves.append(r.val)
                
            if r.left:
                stack.append(r.left)
            
            if r.right:
                stack.append(r.right)
        
        return r_leaves
    
    def leafSimilar(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
        
        return self.dfs(root1) == self.dfs(root2)
        