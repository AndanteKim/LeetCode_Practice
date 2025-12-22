# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def longestConsecutive(self, root: Optional[TreeNode]) -> int:
        def longest_path(node: Optional[TreeNode]) -> List[int]:
            nonlocal max_val

            if not node:
                return [0, 0]

            inc = dec = 1
            if node.left:
                left = longest_path(node.left)
                if node.val == node.left.val + 1:
                    dec = left[1] + 1
                elif node.val == node.left.val - 1:
                    inc = left[0] + 1
            
            if node.right:
                right = longest_path(node.right)
                if node.val == node.right.val + 1:
                    dec = max(dec, right[1] + 1)
                elif node.val == node.right.val - 1:
                    inc = max(inc, right[0] + 1)
            
            max_val = max(max_val, inc + dec - 1)
            return [inc, dec]

        max_val = 0
        longest_path(root)
        return max_val