# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def flipEquiv(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
        # Both trees are empty
        if not (root1 or root2):
            return True
        
        # Just one of the trees is empty
        if not (root1 and root2):
            return False
        
        # Corresponding values differ
        if root1.val != root2.val:
            return False
        
        # Check if corresponding subtrees are flip equivalent
        no_swap = self.flipEquiv(root1.left, root2.left) and self.flipEquiv(root1.right, root2.right)
        
        # Check if opposite subtrees are flip equivalent
        swap = self.flipEquiv(root1.left, root2.right) and self.flipEquiv(root1.right, root2.left)
        
        return no_swap or swap