# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pseudoPalindromicPaths (self, root: Optional[TreeNode]) -> int:
        count = 0
        stack = [(root, 0)]
        
        while stack:
            node, path = stack.pop()
            
            if node:
                # Compute occurrences of each digit in the corresponding register
                path ^= (1 << node.val)
                # If it's a leaf, check if the path is pseudo-palindromic
                if not (node.left or node.right):
                    # check if at most one digit has an odd frequency
                    if path & (path - 1) == 0:
                        count += 1
                        
                else:
                    stack.append((node.right, path))
                    stack.append((node.left, path))
                    
        return count
                