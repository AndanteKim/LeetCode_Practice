# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findBottomLeftValue(self, root: Optional[TreeNode]) -> int:
        self.max_depth = -1
        self.bottom_left_value = 0
        self.dfs(root, 0)
        
        return self.bottom_left_value
    
    def dfs(self, current: TreeNode, depth: int) -> None:
        if not current:
            return
        
        # If true, we discovered a new level
        if depth > self.max_depth:
            self.max_depth = depth
            self.bottom_left_value = current.val
            
        self.dfs(current.left, depth + 1)
        self.dfs(current.right, depth + 1)
        
        return