# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minDiffInBST(self, root: Optional[TreeNode]) -> int:
        flattened = []
        
        def dfs(node: Optional[TreeNode]) -> None:
            if not node: return
            dfs(node.left)
            flattened.append(node.val)
            dfs(node.right)
        
        dfs(root)
        ans = float('inf')
        for i in range(1, len(flattened)):
            ans = min(ans, flattened[i] - flattened[i-1])
        return ans