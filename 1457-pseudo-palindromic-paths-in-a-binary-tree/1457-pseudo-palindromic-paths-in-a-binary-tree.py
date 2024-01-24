# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pseudoPalindromicPaths (self, root: Optional[TreeNode]) -> int:
        def preorder(node: Optional[TreeNode], path: int) -> None:
            nonlocal count
            if node:
                # comput occurrences of each digit in the corresponding register
                path ^= (1 << node.val)
                
                # If it's a leaf, check if the path is pseudo-palindromic
                if not (node.left or node.right):
                    # check if at most one digit has an odd frequency
                    if path & (path - 1) == 0:
                        count += 1
                    
                else:
                    preorder(node.left, path)
                    preorder(node.right, path)
        
        
        count = 0
        preorder(root, 0)
        
        return count