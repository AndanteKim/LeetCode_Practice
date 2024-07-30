# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        # Post order traversal of subtree rooted at 'node'
        def gain_from_subtree(node: TreeNode) -> int:
            nonlocal max_sum
            
            if not node:
                return 0
            
            # Add the gain from the left subtree. Note that if the
            # gain is negative, we can ignore it, or count it as 0.
            # This is the reason we use 'max' here.
            gain_from_left = max(gain_from_subtree(node.left), 0)
            
            # add the gain / path sum from the right subtree. 0 if negative
            gain_from_right = max(gain_from_subtree(node.right), 0)
            
            # If left or right gain are negative, they are counted as 0,
            # so this statement takes care of all four scenarios.
            max_sum = max(max_sum, gain_from_left + gain_from_right + node.val)
            
            # Return the max sum for a path starting at the root of subtree.
            return max(gain_from_left + node.val, gain_from_right + node.val)
        
        max_sum = float('-inf')
        gain_from_subtree(root)
        return max_sum