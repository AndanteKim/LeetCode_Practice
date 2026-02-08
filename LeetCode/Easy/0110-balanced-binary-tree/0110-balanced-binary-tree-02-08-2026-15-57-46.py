# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        def dfs(node: Optional[TreeNode]) -> int:
            if not node:
                return 0

            left, right = dfs(node.left), dfs(node.right)
            return 1 + max(left, right)
        
        if not root:
            return True

        left, right = -1 + dfs(root.left), 1 + dfs(root.right)
        return (abs(dfs(root.left) - dfs(root.right)) <= 1
            and self.isBalanced(root.left)
            and self.isBalanced(root.right)
        )
