# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumOfLeftLeaves(self, root: Optional[TreeNode]) -> int:
        
        if not root: return 0
        
        def process_subtree(subtree, is_left):
            if not (subtree.left or subtree.right):
                return subtree.val if is_left else 0
            
            total = 0
            if subtree.left:
                total += process_subtree(subtree.left, True)
            
            if subtree.right:
                total += process_subtree(subtree.right, False)
            return total
        
        return process_subtree(root, False)
            