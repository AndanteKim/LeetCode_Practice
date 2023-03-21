# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    result = 0
    def helper(self, node: Optional[TreeNode], cur_max: int, cur_min: int) -> None:
        if not node:
            return
        
        self.result = max(self.result, abs(cur_max - node.val), abs(cur_min - node.val))
        cur_max = max(cur_max, node.val)
        cur_min = min(cur_min, node.val)
        self.helper(node.left, cur_max, cur_min)
        self.helper(node.right, cur_max, cur_min)
    
    def maxAncestorDiff(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        self.helper(root, root.val, root.val)
        return self.result