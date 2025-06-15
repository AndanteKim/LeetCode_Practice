# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def checkEqualTree(self, root: Optional[TreeNode]) -> bool:
        def dfs(node: Optional[TreeNode]) -> int: 
            if not node:
                return 0
            
            seen.append(dfs(node.left) + dfs(node.right) + node.val)
            return seen[-1]
        
        seen = []
        total = dfs(root)
        seen.pop()
        return total / 2.0 in seen