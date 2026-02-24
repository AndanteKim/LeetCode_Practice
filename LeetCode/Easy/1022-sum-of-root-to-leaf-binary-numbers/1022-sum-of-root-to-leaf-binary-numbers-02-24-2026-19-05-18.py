# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumRootToLeaf(self, root: Optional[TreeNode]) -> int:
        def dfs(node: Optional[TreeNode], curr: int) -> None:
            if not node:
                return

            if not (node.left or node.right):
                self.ans += (curr << 1) + node.val
                return

            dfs(node.left, (curr << 1) + node.val)
            dfs(node.right, (curr << 1) + node.val)

        self.ans = 0
        dfs(root, 0)

        return self.ans