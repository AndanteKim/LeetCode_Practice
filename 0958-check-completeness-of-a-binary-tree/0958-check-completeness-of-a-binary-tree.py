# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def countNodes(self, root: Optional[TreeNode]) -> int:
        if not root: return 0
        return 1 + self.countNodes(root.left) + self.countNodes(root.right)
    
    def dfs(self, node: Optional[TreeNode], index: int, n: int) -> bool:
        if not node:
            return True
        
        if index >= n:
            return False
        
        return self.dfs(node.left, 2 * index + 1, n) and self.dfs(node.right, 2 * index + 2, n)
    
    def isCompleteTree(self, root: Optional[TreeNode]) -> bool:
        return self.dfs(root, 0, self.countNodes(root))