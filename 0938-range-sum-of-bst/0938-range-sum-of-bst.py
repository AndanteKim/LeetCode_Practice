# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rangeSumBST(self, root: Optional[TreeNode], low: int, high: int) -> int:
        total = 0
        stack = [root]
        
        while stack:
            elem = stack.pop()
            if low <= elem.val <= high:
                total += elem.val
            
            if elem.left:
                stack.append(elem.left)
            
            if elem.right:
                stack.append(elem.right)
        
        return total
        
        