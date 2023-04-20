# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, node: Optional[TreeNode], level: int, last_val: DefaultDict[int, int]) -> bool:
        if not node:
            return True
        
        if level % 2 == 0:
            if node.val % 2 == 0 or (last_val[level] and last_val[level] >= node.val):
                return False
            last_val[level] = node.val
        else:
            if node.val % 2 == 1 or (last_val[level] and last_val[level] <= node.val):
                return False
            last_val[level] = node.val
        return self.dfs(node.left, level + 1, last_val) and self.dfs(node.right, level + 1, last_val)
                
    
    def isEvenOddTree(self, root: Optional[TreeNode]) -> bool:
        last_val = defaultdict(int)
        return self.dfs(root, 0, last_val)
        