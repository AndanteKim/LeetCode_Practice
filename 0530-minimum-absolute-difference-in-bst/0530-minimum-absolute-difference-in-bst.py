# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, root: Optional[TreeNode]) -> List[int]:
        if not root:
            return []
        return self.dfs(root.left) + [root.val] + self.dfs(root.right)
    
    def getMinimumDifference(self, root: Optional[TreeNode]) -> int:
        arr, ans = self.dfs(root), float('inf')
        
        for i in range(len(arr) - 1):
            ans = min(ans, arr[i + 1] - arr[i])
        
        return ans
        