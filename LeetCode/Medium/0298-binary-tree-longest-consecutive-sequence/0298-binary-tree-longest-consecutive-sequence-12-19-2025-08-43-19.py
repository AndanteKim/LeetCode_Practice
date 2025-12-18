# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def longestConsecutive(self, root: Optional[TreeNode]) -> int:
        def dfs(child: Optional[TreeNode], parent: Optional[TreeNode], length: int) -> int:
            if not child:
                return length

            length = length + 1 if parent and parent.val + 1 == child.val else 1

            return max(length, dfs(child.left, child, length), dfs(child.right, child, length))

        if not root:
            return 0

        return dfs(root, None, 0)