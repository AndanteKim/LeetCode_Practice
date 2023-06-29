# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, node: Optional[TreeNode]) -> Tuple[bool, int]:
        if not node:
            return True, 0
        
        left = self.dfs(node.left)
        right = self.dfs(node.right)
        isLeftUniValue = left[0]
        isRightUniValue = right[0]
        count = left[1] + right[1]
        
        if isLeftUniValue and isRightUniValue:
            if node.left and node.val != node.left.val:
                return False, count
            if node.right and node.val != node.right.val:
                return False, count
            return True, count + 1
        return False, count
    
    def countUnivalSubtrees(self, root: Optional[TreeNode]) -> int:
        return self.dfs(root)[1]