# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxProduct(self, root: Optional[TreeNode]) -> int:
        def tree_sum(node: Optional[TreeNode]) -> int:
            if not node:
                return 0

            left_sum = tree_sum(node.left)
            right_sum = tree_sum(node.right)
            total_sum = left_sum + right_sum + node.val
            all_sums.append(total_sum)
            return total_sum
        
        all_sums = []
        ans, total = 0, tree_sum(root)
        mod = 10 ** 9 + 7
        
        for curr in all_sums:
            ans = max(ans, (curr * (total - curr)))
        
        return ans % mod