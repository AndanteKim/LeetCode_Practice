# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, node: Optional[TreeNode], depth: int, col_index: int) -> None:
        if not node:
            return
        
        if depth not in self.first_col_index_table:
            self.first_col_index_table[depth] = col_index
        
        self.ans = max(self.ans, col_index - self.first_col_index_table[depth] + 1)
        
        self.dfs(node.left, depth + 1, 2 * col_index)
        self.dfs(node.right, depth + 1, 2 * col_index + 1)
    
    def widthOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        self.first_col_index_table = dict()
        self.ans = 0
        
        self.dfs(root, 0, 0)
        return self.ans