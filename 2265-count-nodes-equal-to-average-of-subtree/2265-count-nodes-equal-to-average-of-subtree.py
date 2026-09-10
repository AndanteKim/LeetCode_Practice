# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def averageOfSubtree(self, root: TreeNode) -> int:
        def dfs(node: TreeNode) -> Tuple[int, int]:
            if not node:
                return (0, 0)

            left, right = dfs(node.left), dfs(node.right)
            total = node.val + left[0] + right[0]
            cnt = 1 + left[1] + right[1]

            if (total // cnt) == node.val:
                self.ans += 1

            return (total, cnt)

        self.ans = 0
        dfs(root)
        return self.ans