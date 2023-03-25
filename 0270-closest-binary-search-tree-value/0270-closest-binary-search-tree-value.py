# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def closestValue(self, root: Optional[TreeNode], target: float) -> int:
        closest = root.val
        while root:
            val = root.val
            closest = val if abs(val - target) < abs(closest - target) else closest
            root = root.left if target < root.val else root.right
        
        return closest