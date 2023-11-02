# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def averageOfSubtree(self, root: Optional[TreeNode]) -> int:
        def dfs(node: Optional[TreeNode]) -> Tuple[int]:
            if not node:
                return (0, 0, 0)
            
            if not node.left and not node.right:
                return (node.val, 1, 1)
            
            left_total, left_count, left_correct = dfs(node.left)
            right_total, right_count, right_correct = dfs(node.right)
            if (left_total + node.val + right_total) // (left_count + right_count + 1) == node.val:
                return (left_total + node.val + right_total, left_count + right_count + 1, left_correct + right_correct + 1)
            return (left_total + node.val + right_total, left_count + right_count + 1, left_correct + right_correct)
                
        total, count, ans = dfs(root)
        return ans