# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def binarySearch(self, root2: Optional[TreeNode], target: int) -> bool:
        if not root2:
            return False
        if root2.val == target:
            return True
        elif root2.val > target:
            return self.binarySearch(root2.left, target)
        else:
            return self.binarySearch(root2.right, target)
    
    def dfs(self, root1: Optional[TreeNode], root2: Optional[TreeNode], target: int) -> bool:
        if not root1:
            return False
        if self.binarySearch(root2, target - root1.val):
            return True
        return self.dfs(root1.left, root2, target) or self.dfs(root1.right, root2, target)
        
    def twoSumBSTs(self, root1: Optional[TreeNode], root2: Optional[TreeNode], target: int) -> bool:
        return self.dfs(root1, root2, target)